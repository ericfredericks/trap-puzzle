
ABTN		= $80
BBTN		= $40
SELECT		= $20
START		= $10
UP			= $08
DOWN		= $04
LEFT		= $02
RIGHT		= $01

SPR_DMA			= $0200
PPU_CTRL		= $2000
PPU_MASK		= $2001
PPU_STATUS		= $2002
OAM_ADDR		= $2003
PPU_SCROLL		= $2005
PPU_ADDR		= $2006
PPU_DATA		= $2007
APU_DMC			= $4010
OAM_DMA			= $4014
JOY1			= $4016
JOY2_FRAME		= $4017

TRUE			= 1
FALSE			= 0

.segment "ZEROPAGE"
	tmp:		.res 2
	tmp2:		.res 2
	tmp3:		.res 2
	tmp4:		.res 2
	tmp5:		.res 2
	tmp6:		.res 2
	tmp7:		.res 2
	tmp8:		.res 2
	input:		.res 1
	lastinput:	.res 1
	frame_counter:	.res 1

.segment "CODE"
load_palette:
; tmp	: palette address
	bit PPU_STATUS
	lda #$3f
	sta PPU_ADDR
	ldy #0
	sty PPU_ADDR
	sty PPU_CTRL
:	lda (tmp),y
	sta PPU_DATA
	iny
	cpy #32
	bne :-
	rts

update_input:
	lda input
	sta lastinput
	lda #1
	sta JOY1
	lda #0
	sta JOY1
	ldx #8
:	lda JOY1
	lsr a
	rol input
	dex
	bne :-
	rts

clear_nametables:
; tmp	: fill byte
	ldx #0
	bit PPU_STATUS
	lda #$20
	sta PPU_ADDR
	stx PPU_ADDR
	stx PPU_CTRL
	lda tmp
	ldy #4
@loop:	
	sta PPU_DATA
	inx
	bne @loop
	dey
	cpy #1
	bne :+
	ldx #$40 ; stop at attribute
	jmp @loop
:	cpy #0
	bne @loop

	ldx #0
	bit PPU_STATUS
	lda #$24
	sta PPU_ADDR
	stx PPU_ADDR
	lda tmp
	ldy #4
@loop2:	
	sta PPU_DATA
	inx
	bne @loop2
	dey
	cpy #1
	bne :+
	ldx #$40
:	cpy #0
	bne @loop2
	rts

clear_attrib:
	bit PPU_STATUS
	lda #$23
	sta PPU_ADDR
	lda #$c0
	sta PPU_ADDR
	lda #0
	sta PPU_CTRL
	ldx #64
:	sta PPU_DATA
	dex
	bne :-

	bit PPU_STATUS
	lda #$27
	sta PPU_ADDR
	lda #$c0
	sta PPU_ADDR
	lda #0
	ldx #64
:	sta PPU_DATA
	dex
	bne :-
	rts

hide_sprites:
	lda #<SPR_DMA
	sta tmp
	lda #>SPR_DMA
	sta tmp+1
	ldx #64
	ldy #0
:	lda #$ff
	sta (tmp),y
	lda tmp
	clc
	adc #4
	sta tmp
	lda tmp+1
	adc #0
	sta tmp+1
	dex
	bne :-
	rts

draw_text:
; tmp	: text address
; tmp2	: xpos
; tmp2+1: ypos
; tmp5	: nametable high byte
	lda tmp2+1
	ror
	ror
	ror
	and #$1f
	clc
	adc tmp5
	sta tmp3+1
	lda tmp2+1
	asl
	asl
	asl
	asl
	asl
	clc
	adc tmp2
	sta tmp3
	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	lda #0
	sta PPU_CTRL

	ldy #0
	lda (tmp),y
	sta tmp3
	iny
:	lda (tmp),y
	sta PPU_DATA
	iny
	cpy tmp3
	bne :-

	rts

attribute_rect:
; tmp	: attrib address
; tmp2	: xpos / 32px
; tmp2+1: ypos / 32px
; tmp5	: nametable high byte
	lda tmp2+1
	asl
	asl
	asl
	clc
	adc #$c0
	clc
	adc tmp2
	sta tmp3
	lda tmp5
	clc
	adc #3
	sta tmp3+1
	bit PPU_STATUS
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	lda #0
	sta PPU_CTRL

	ldy #0
	lda (tmp),y
	sta tmp4
	iny
	lda (tmp),y
	sta tmp4+1
	iny
	ldx #0
@loop:
	lda (tmp),y
	sta PPU_DATA
	iny
	inx
	cpx tmp4
	bne :+
	ldx #0
	lda tmp3
	clc
	adc #8
	sta tmp3
	lda tmp3+1
	adc #0
	sta tmp3+1
	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
:	cpy tmp4+1
	bne @loop
	rts

draw_column:
; tmp	: tile
; tmp2	: xpos
; tmp2+1: ypos
; tmp4	: length
; tmp5	: nametable high byte
	lda tmp2+1
	ror
	ror
	ror
	and #$1f
	clc
	adc tmp5
	sta tmp3+1
	lda tmp2+1
	asl
	asl
	asl
	asl
	asl
	clc
	adc tmp2
	sta tmp3
	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	lda #4
	sta PPU_CTRL

	ldy #0
	lda tmp
@loop:	
	sta PPU_DATA
	iny
	cpy tmp4
	beq :+
	jmp @loop
:	rts

draw_vertical_image:
; tmp	: image address
; tmp2	: xpos
; tmp2+1: ypos
; tmp5	: nametable high byte
	lda tmp2+1
	ror
	ror
	ror
	and #$1f
	clc
	adc tmp5
	sta tmp3+1
	lda tmp2+1
	asl
	asl
	asl
	asl
	asl
	clc
	adc tmp2
	sta tmp3
	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	lda #4
	sta PPU_CTRL

	; every image starts with a row/column length
	; then a total length (including itself and the above)
	ldy #0
	lda (tmp),y
	sta tmp4
	iny
	lda (tmp),y
	sta tmp4+1
	iny

	ldx #0
:	lda (tmp),y
	sta PPU_DATA
	iny
	inx
	cpx tmp4
	bne :+
	lda tmp3
	clc
	adc #1
	sta tmp3
	lda tmp3+1
	adc #0
	sta tmp3+1
	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	ldx #0
:	cpy tmp4+1
	bne :--

	rts

draw_horizontal_image:
; tmp	: image address
; tmp2	: xpos
; tmp2+1: ypos
; tmp5	: nametable high byte
	lda tmp2+1
	ror
	ror
	ror
	and #$1f
	clc
	adc tmp5
	sta tmp3+1
	lda tmp2+1
	asl
	asl
	asl
	asl
	asl
	clc
	adc tmp2
	sta tmp3
	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	lda #0
	sta PPU_CTRL

	ldy #0
	lda (tmp),y
	sta tmp4
	iny
	lda (tmp),y
	sta tmp4+1
	iny
	
	ldx #0
:	lda (tmp),y
	sta PPU_DATA
	iny
	inx
	cpx tmp4
	bne :+
	lda tmp3
	clc
	adc #$20
	sta tmp3
	lda tmp3+1
	adc #0
	sta tmp3+1
	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	ldx #0
:	cpy tmp4+1
	bne :--

	rts
