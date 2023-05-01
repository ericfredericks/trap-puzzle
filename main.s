
	.include "nes.inc"
	.include "trap_puzzle.inc"

.segment "HEADER"
	.byte "NES",$1a
	.byte $02
	.byte $01
	.byte %00000001
	.byte %00001000
	.byte 0,0,0,0,0,0,0,0

.segment "CODE"
reset:
	sei
	cld
	ldx #$40
	stx JOY2_FRAME
	ldx #$ff
	txs
	inx
	stx PPU_CTRL
	stx PPU_MASK
	stx APU_DMC
:	bit PPU_STATUS
	bpl :-
	lda #0
@clrmem:
	sta $00,x
	sta $0100,x
	sta $0200,x
	sta $0300,x
	sta $0400,x
	sta $0500,x
	sta $0600,x
	sta $0700,x
	inx
	bne @clrmem
:	bit PPU_STATUS
	bpl :-
	
	jsr tp_init_var

	; enable nmi
	lda #$80
	sta PPU_CTRL

readyloop:
	lda frame_counter
:	cmp frame_counter
	beq :-

	lda rendering_on
	beq :+
	jsr update_input
	jsr tp_tick_screen
:

	jmp readyloop

nmi:
	pha

	lda #<SPR_DMA
	sta OAM_ADDR
	lda #>SPR_DMA
	sta OAM_DMA

	lda #0
	sta PPU_CTRL
	sta PPU_MASK

	lda screen
	cmp lastscreen
	beq :+
	lda #0
	sta rendering_on
	jsr tp_init_screen
:	jsr tp_frame_screen

	bit PPU_STATUS
	lda #0
	sta PPU_SCROLL
	sta PPU_SCROLL

	lda #%10011000
	ora swap_nametable
	sta PPU_CTRL
	lda #%00011110
	ora emphasis_bits
	and rendering_on
	sta PPU_MASK

	inc frame_counter
	pla
	rti

.segment "VECTORS"
	.word nmi
	.word reset
	.word 0
