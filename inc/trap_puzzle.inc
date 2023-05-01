
.segment "CHARS"
	.incbin "chr/00.chr"

.segment "ZEROPAGE"
TITLE		= 0
LEVEL		= 1
MENU		= 2
	screen:		.res 1
	lastscreen:	.res 1
	
GEN			= 0
FALL		= 1
LOCK		= 2
PATTERN		= 3
REDRAW		= 4
	phase:		.res 1
	
U_PIECE		= 0
T_PIECE		= 1
J_PIECE		= 2
L_PIECE		= 3
I_PIECE		= 4
	piece_x:	.res 1
	piece_y:	.res 1
	next_piece_type:.res 1
	piece_type:	.res 1
	piece_coll:	.res 2
	piece_rot:	.res 1

	lock_timer:		.res 1
	lock_start_y:	.res 1
	lock_timer_step:		.res 1
	fall_timer:		.res 1
	inside_block:		.res 1
	pattern_timer:	.res 1
	soft_drop_counter:	.res 1

MASK_MATRIX		= $03C8
TMP_MATRIX		= $0490
TMP_MATRIX_2	= TMP_MATRIX + 50
TMP_MATRIX_3	= TMP_MATRIX + 100
TMP_MATRIX_4	= TMP_MATRIX + 150
	amt_traps:		.res 1
	sizes_traps:	.res 36
	clear_traps_frame:.res 1
	size_traps:.res 1

	current_level:	.res 1
	traps_lines_counter: .res 1
	prev_traps_lines_counter:	.res 1

	random:	.res 10
	garbage_prev_row_mask:	.res 10
	garbage_counter:	.res 1

	; scores & area are stored as bcd
	score:	.res 6
	top_score:	.res 6
	area:		.res 3

	; "menu_0" refers to the level select
	; "menu_1" means the music select
	music_select:	.res 1
	menu_select:	.res 1
	prev_menu_0_ppu_addr:	.res 2
	prev_menu_1_ppu_addr:	.res 2
	prev_menu_bar_0_ppu_addr:	.res 2
	prev_menu_bar_1_ppu_addr:	.res 2

MATRIX			= $0300
MATRIX_2		= MATRIX + 50
MATRIX_3		= MATRIX + 100
MATRIX_4		= MATRIX + 150
MATRIX_X	= 3
MATRIX_Y	= 5

MATRIX_PPU_LOC	= $2000 + MATRIX_Y<<5 + MATRIX_X
MATRIX_PPU_LOC_2= MATRIX_PPU_LOC + 5*32
MATRIX_PPU_LOC_3= MATRIX_PPU_LOC + 10*32
MATRIX_PPU_LOC_4= MATRIX_PPU_LOC + 15*32
	matrix_ppu_loc:	.res 2
	matrix_ppu_loc_2:.res 2
	matrix_ppu_loc_3:.res 2
	matrix_ppu_loc_4:.res 2

	redraw_in_progress:	.res 1
	redraw_complete:	.res 1
	redraw_frame:	.res 1
	swap_nametable:	.res 1

	emphasis_bits:	.res 1
	paused:			.res 1

	game_over:		.res 1
	game_over_fc:	.res 1

	rendering_on:	.res 1
	init_screen_frame:	.res 1

.segment "RODATA"
SPACE		= $25
BLOCK		= $8c
EMPTY		= $8e
DASH		= $7a
ARROW_RIGHT	= $2c
ARROW_UP	= $2d
BAR			= $5a
title_palette:
	.byte $0f,$26,$28,$30,$0f,$00,$00,$00,$0f,$00,$00,$00,$0f,$00,$00,$00
	.byte $0f,$00,$00,$00,$0f,$00,$00,$00,$0f,$00,$00,$00,$0f,$00,$00,$00
menu_palette:
	.byte $0f,$00,$01,$30,$0f,$00,$00,$00,$0f,$00,$00,$00,$0f,$00,$00,$00
	.byte $0f,$00,$00,$00,$0f,$00,$00,$00,$0f,$00,$00,$00,$0f,$00,$00,$00
level_palette:
	.byte $3a,$0f,$01,$10,$3a,$0f,$12,$10,$3a,$0b,$1b,$3c,$3a,$0b,$21,$3c
	.byte $3a,$0f,$01,$10,$3a,$0f,$12,$10,$3a,$00,$2b,$3c,$3a,$00,$31,$3c
txt_marathon:
	.byte 11+1
	.byte $2f,$19,$25,$16,$0a,$1b,$0a,$1d,$11,$18,$17
txt_1player:
	.byte 8+1
	.byte $2f,$25,$19,$15,$0a,$22,$0e,$1b
txt_2players:
	.byte 9+1
	.byte $02,$25,$19,$15,$0a,$22,$0e,$1b,$1c
txt_copy:
	.byte 25+1
	.byte $24,$25,$02,$2e,$02,$02,$25,$10,$1b,$0e,$0e,$17,$25,$19,$12,$0c	; "c 2022 GREEN PIC
	.byte $1d,$1e,$1b,$0e,$1c,$25,$0c,$18,$2b								; TURES CO."
txt_press_start:
	.byte 19+1
	.byte $19,$1b,$0e,$1c,$1c,$25,$1c,$1d,$0a,$1b,$1d,$25,$1d,$18,$25,$19	; "PRESS START TO P
	.byte $15,$0a,$22														; LAY"
txt_level:
	.byte 5+1
	.byte $15,$0e,$1f,$0e,$15
txt_level_settings:
	.byte 13+1
	.byte $2e,$25,$2f,$25,$02,$25,$03,$25,$04,$25,$05,$25,$06
txt_music:
	.byte 5+1
	.byte $16,$1e,$1c,$12,$0c
txt_baroque_rus:
	.byte 13+1
	.byte $0b,$0a,$1b,$18,$1a,$1e,$0e,$25,$25,$25,$1b,$1e,$1c
txt_to_game:
	.byte 7+1
	.byte $1d,$2e,$25,$10,$0a,$16,$0e
txt_press_start_2:
	.byte 12+1
	.byte $19,$1b,$0e,$1c,$1c,$25,$25,$1c,$1d,$0a,$1b,$1d
txt_game_over:
	.byte 10+1
	.byte $10,$0a,$16,$0e,$25,$25,$18,$1f,$0e,$1b
img_trap:
	.byte 17
	.byte 17*5+2
	.byte $30,$31,$32,$31,$33,$32,$31,$34,$35,$36,$31,$34,$37,$32,$31,$34,$38
	.byte $25,$30,$39,$3a,$30,$39,$33,$39,$33,$39,$33,$39,$33,$39,$33,$39,$3a
	.byte $25,$30,$39,$3a,$30,$39,$3b,$3c,$3d,$39,$33,$39,$33,$39,$3e,$3f,$40
	.byte $25,$30,$39,$3a,$30,$39,$33,$41,$33,$39,$31,$39,$33,$39,$42,$43,$25
	.byte $25,$30,$44,$3a,$30,$44,$33,$44,$33,$44,$33,$44,$33,$44,$3a,$25,$25
img_puzzle:
	.byte 24
	.byte 24*5+2
	.byte $30,$32,$31,$34,$37,$32,$33,$32,$33,$31,$45,$32,$33,$31,$45,$32,$33
	.byte $32,$3a,$46,$36,$31,$31,$3a
	.byte $30,$39,$33,$39,$33,$39,$33,$39,$3a,$47,$48,$39,$3a,$47,$48,$39,$33
	.byte $39,$3a,$30,$39,$3a,$25,$25
	.byte $30,$39,$3e,$3f,$56,$39,$33,$39,$4a,$4b,$39,$4c,$4d,$4b,$39,$4c,$4e
	.byte $39,$3a,$30,$39,$31,$31,$3a
	.byte $30,$39,$42,$43,$30,$39,$33,$39,$33,$39,$4f,$50,$30,$39,$4f,$50,$30
	.byte $39,$3a,$30,$39,$3a,$25,$25
	.byte $30,$44,$3a,$25,$51,$52,$44,$53,$54,$44,$57,$31,$33,$44,$57,$31,$33
	.byte $44,$31,$55,$52,$31,$31,$3a
img_column_0:
	.byte 25
	.byte 25*2+2
	.byte $5c,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$25,$25,$25,$25,$25,$25,$25,$25,$25,$25,$5c,$8f,$8f,$8f,$8f,$8f
	.byte $5c,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$90,$91,$92,$92,$93,$94,$25,$94,$95,$96,$97,$8f,$8f,$8f,$8f,$8f
img_column_1:
	.byte 25
	.byte 25*4+2
	.byte $5c,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$a0,$6b,$a8,$ab,$a3,$a5
	.byte $5c,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$a1,$6c,$a9,$ac,$af,$a6
	.byte $5c,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$a1,$6d,$aa,$ad,$b0,$a6
	.byte $5c,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$a2,$6e,$a4,$ae,$a4,$a7
img_column_2:
	.byte 25
	.byte 25*2+2
	.byte $5c,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$98,$99,$9a,$9b,$25,$9b,$9c,$9d,$9d,$9e,$9f,$8f,$8f,$8f,$8f,$8f
	.byte $5c,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$8f,$25,$25,$25,$25,$25,$25,$25,$25,$25,$25,$5c,$8f,$8f,$8f,$8f,$8f
img_matrix_top:
	.byte 12
	.byte 12*3+2
	.byte $7b,$7c,$7c,$7c,$7c,$7c,$7c,$7c,$7c,$7c,$7c,$7d
	.byte $5b,$27,$27,$27,$26,$26,$26,$26,$27,$27,$27,$27
	.byte $27,$60,$61,$62,$26,$26,$26,$26,$27,$27,$27,$27
img_matrix_bottom:
	.byte 12
	.byte 12*3+2
	.byte $27,$63,$64,$65,$27,$27,$27,$27,$27,$27,$27,$27
	.byte $27,$66,$67,$68,$27,$27,$27,$27,$27,$27,$27,$27
	.byte $7e,$27,$27,$27,$27,$27,$27,$27,$27,$27,$27,$7f
img_card_top:
	.byte 12
	.byte 12*2+2
	.byte $5d,$26,$26,$26,$26,$26,$26,$26,$26,$26,$26,$5e
	.byte $26,$26,$26,$26,$26,$26,$26,$26,$26,$26,$26,$26
img_card_bottom:
	.byte 12
	.byte 12*4+2
	.byte $26,$26,$26,$26,$26,$26,$26,$26,$26,$26,$26,$26
	.byte $26,$69,$6a,$26,$26,$26,$26,$26,$26,$26,$26,$26
	.byte $26,$26,$26,$26,$26,$26,$26,$26,$26,$26,$26,$26
	.byte $8a,$26,$26,$26,$26,$26,$26,$26,$26,$26,$26,$8b
img_card:
	.byte 20
	.byte 20*12+2
	.byte $28,$28,$28,$28,$28, $28,$d0,$28,$28,$28, $f8,$26,$26,$f7,$27, $27,$e0,$e2,$e4,$28
	.byte $28,$28,$28,$28,$28, $cc,$d1,$d3,$d5,$d8, $fb,$fc,$26,$f6,$27, $27,$e1,$e3,$e5,$e8
	.byte $28,$c3,$c6,$c8,$ca, $cd,$26,$26,$26,$d9, $28,$f8,$26,$f7,$27, $27,$27,$27,$e6,$e9
	.byte $28,$c4,$26,$26,$26, $c0,$c1,$c0,$c0,$26, $26,$c0,$c0,$c0,$c2, $c2,$c2,$c2,$e7,$28
	.byte $28,$c5,$c7,$c9,$cb, $ce,$26,$26,$d6,$da, $dc,$fc,$26,$f4,$27, $27,$27,$27,$ec,$ea
	.byte $28,$28,$28,$28,$28, $cf,$d2,$d4,$d7,$db, $28,$f0,$f2,$28,$27, $27,$27,$27,$ed,$28
	.byte $28,$28,$28,$28,$28, $28,$28,$28,$28,$28, $28,$f1,$f3,$f5,$27, $27,$27,$27,$ee,$eb
	.byte $28,$28,$28,$28,$28, $28,$28,$28,$28,$28, $f8,$26,$26,$b7,$26, $26,$bf,$27,$ef,$fd
	.byte $28,$28,$28,$28,$28, $28,$28,$28,$28,$28, $f9,$26,$b5,$b8,$bb, $bd,$dd,$26,$26,$fe
	.byte $28,$28,$28,$28,$28, $28,$28,$28,$28,$fa, $26,$26,$b6,$b9,$bc, $be,$de,$26,$26,$fe
	.byte $28,$28,$28,$28,$28, $28,$28,$28,$28,$fb, $fc,$26,$26,$ba,$26, $26,$df,$27,$ed,$ff
	.byte $28,$28,$28,$28,$28, $28,$28,$28,$28,$28, $f9,$26,$26,$f6,$27, $27,$27,$27,$ee,$eb
attrib_card:
	.byte 4
	.byte 4*5+2
	.byte %10001000,%10101010,%10101010,%00100010
	.byte %10001000,%10101010,%10101010,%00100010
	.byte %10001000,%10101010,%10101010,%00100010
	.byte %11001000,%11111111,%10111010,%00110010
	.byte %11001100,%11111111,%10111011,%00110011
fall_times:
	.byte 60,45,30,23,15,8,1
level_requirement:
	.byte 10,20,30,40,50,60,70
menu_bar_0_ppu_addr:
	.byte $25,$21,$c5,$21,$65,$22
menu_bar_1_ppu_addr:
	.byte $a5,$21,$45,$22,$c5,$22
u_piece_next:
	.byte 1,0,1,1,1,1
t_piece_next:
	.byte 1,1,1,0,1,0
j_piece_next:
	.byte 1,1,1,0,0,1
l_piece_next:
	.byte 1,1,1,1,0,0
i_piece_next:
	.byte 0,0,0,1,1,1
u_piece_coll:
	.byte 1,0,1,1,1,1,0,0,0
	.byte 0,1,1,0,1,0,0,1,1
	.byte 0,0,0,1,1,1,1,0,1
	.byte 1,1,0,0,1,0,1,1,0
t_piece_coll:
	.byte 0,0,0,1,1,1,0,1,0
	.byte 0,1,0,1,1,0,0,1,0
	.byte 0,1,0,1,1,1,0,0,0
	.byte 0,1,0,0,1,1,0,1,0
j_piece_coll:
	.byte 0,0,0,1,1,1,0,0,1
	.byte 0,1,0,0,1,0,1,1,0
	.byte 1,0,0,1,1,1,0,0,0
	.byte 0,1,1,0,1,0,0,1,0
l_piece_coll:
	.byte 0,0,0,1,1,1,1,0,0
	.byte 1,1,0,0,1,0,0,1,0
	.byte 0,0,1,1,1,1,0,0,0
	.byte 0,1,0,0,1,0,0,1,1
i_piece_coll:
	.byte 0,0,0,1,1,1,0,0,0
	.byte 0,1,0,0,1,0,0,1,0
	.byte 0,0,0,1,1,1,0,0,0
	.byte 0,1,0,0,1,0,0,1,0
.segment "CODE"
tp_tick_screen:
	lda screen
	sta lastscreen

@title:
	cmp #TITLE
	bne @menu
	lda input
	and #START
	beq :+
	lda #MENU
	sta screen
:	rts

@menu:
	cmp #MENU
	beq :+
	jmp @level
:	
	lda menu_select
	beq :+
	lda input
	and #UP
	beq :+
	lda input
	eor lastinput
	and #UP
	beq :+
	dec menu_select
:	lda menu_select
	cmp #2
	beq :+
	lda input
	and #DOWN
	beq :+
	lda input
	eor lastinput
	and #DOWN
	beq :+
	inc menu_select
:
	lda menu_select
	bne @menu_0_not_selected
	lda current_level
	beq :+
	lda input
	and #LEFT
	beq :+
	lda input
	eor lastinput
	and #LEFT
	beq :+
	dec current_level
:	lda current_level
	cmp #6
	beq :+
	lda input
	and #RIGHT
	beq :+
	lda input
	eor lastinput
	and #RIGHT
	beq :+
	inc current_level
:	rts
@menu_0_not_selected:
	cmp #1
	bne @menu_1_not_selected
	lda music_select
	beq :+
	lda input
	and #LEFT
	beq :+
	lda input
	eor lastinput
	and #LEFT
	beq :+
	lda music_select
	eor #1
	sta music_select
:	lda music_select
	bne :+
	lda input
	and #RIGHT
	beq :+
	lda input
	eor lastinput
	and #RIGHT
	beq :+
	lda music_select
	eor #1
	sta music_select
:	rts
@menu_1_not_selected:
	lda input
	and #START
	beq :+
	lda input
	eor lastinput
	and #START
	beq :+
	lda #LEVEL
	sta screen
:	rts

@level:
	lda game_over
	beq @not_game_over
	lda game_over_fc
	cmp #$ff
	beq :+
	inc game_over_fc
:	lda input
	and #START
	beq :+
	jsr tp_update_score
	lda #0
	sta menu_select
	sta swap_nametable
	lda #MENU
	sta screen
:	rts
@not_game_over:
	lda input
	and #START
	beq :+
	lda input
	eor lastinput
	and #START
	beq :+
	lda paused
	eor #1
	sta paused
:	lda paused
	beq :+
	rts
:
@gen:	
	lda phase
	cmp #GEN
	bne @lock
	jsr tp_piece_init
	lda #FALL
	sta phase
	lda #0
	sta inside_block
	ldy current_level
	lda fall_times,y
	sta fall_timer
	rts
@lock:	
	lda phase
	cmp #LOCK
	bne @fall
	lda #TRUE
	sta lock_timer_step
	lda inside_block
	bne :+
	lda #0
	sta tmp3
	lda #1
	sta tmp3+1
	jsr tp_piece_collision
	cmp #FALSE
	bne :+
	lda lock_start_y
	cmp piece_y
	bcc @lock_y_less_piece_y
	lda #FALSE
	sta lock_timer_step
	jmp :+
@lock_y_less_piece_y:
	lda #FALL
	sta phase
	ldy current_level
	lda fall_times,y
	sta fall_timer
:	
	lda lock_timer
	bne :+
	lda #PATTERN
	sta phase
	lda #10
	sta pattern_timer
	inc garbage_counter
	rts
:
	lda lock_timer_step
	cmp #TRUE
	bne :+
	dec lock_timer
:
@fall:
	lda phase
	cmp #FALL
	beq :+
	cmp #LOCK
	beq :+
	jmp @pattern
:	
	lda inside_block
	beq :+
	rts
:
	lda phase
	cmp #FALL
	bne :+
	lda #0
	sta tmp3
	lda #0
	sta tmp3+1
	jsr tp_piece_collision
	cmp #TRUE
	bne :+
	lda #LOCK
	sta phase
	lda #60
	sta lock_timer
	lda piece_y
	sta lock_start_y
	lda #TRUE
	sta inside_block
	rts
:
	lda fall_timer
	bne :+
	ldy current_level
	lda fall_times,y
	sta fall_timer
	lda #0
	sta tmp3
	lda #1
	sta tmp3+1
	jsr tp_piece_collision
	cmp #FALSE
	bne :+
	inc piece_y
:	dec fall_timer ; will wrap
	
	lda input
	and #LEFT
	beq :+
	lda input
	eor lastinput
	and #LEFT
	beq :+
	lda #$ff
	sta tmp3
	lda #0
	sta tmp3+1
	jsr tp_piece_collision
	cmp #FALSE
	bne :+
	dec piece_x
:
	lda input
	and #RIGHT
	beq :+
	lda input
	eor lastinput
	and #RIGHT
	beq :+
	lda #1
	sta tmp3
	lda #0
	sta tmp3+1
	jsr tp_piece_collision
	cmp #FALSE
	bne :+
	inc piece_x
:
	lda input
	and #DOWN
	bne :+
	lda #0
	sta soft_drop_counter
	jmp @end_soft_drop
:	inc soft_drop_counter
	lda input
	eor lastinput
	and #DOWN
	bne :+
	lda soft_drop_counter
	cmp #20
	bcc @end_soft_drop
:	lda #0
	sta tmp3
	lda #1
	sta tmp3+1
	jsr tp_piece_collision
	cmp #FALSE
	beq :+
	lda #0
	sta soft_drop_counter
	jmp @end_soft_drop
:	inc piece_y
	ldy current_level
	lda fall_times,y
	sta fall_timer
@end_soft_drop:

	lda input
	and #UP
	beq :++
	lda input
	eor lastinput
	and #UP
	beq :++
	lda #PATTERN
	sta phase
	lda #10
	sta pattern_timer
	inc garbage_counter
:	lda #0
	sta tmp3
	lda #1
	sta tmp3+1
	jsr tp_piece_collision
	cmp #FALSE
	bne :+
	inc piece_y
	jmp :-
	rts
:
	lda input
	and #ABTN
	beq :+
	lda input
	eor lastinput
	and #ABTN
	beq :+
	lda #0
	sta tmp
	jsr tp_piece_rotate
:
	lda input
	and #BBTN
	beq :+
	lda input
	eor lastinput
	and #BBTN
	beq :+
	lda #$ff
	sta tmp
	jsr tp_piece_rotate
:
	lda phase
	cmp #FALL
	bne :+
	lda #0
	sta tmp3
	lda #1
	sta tmp3+1
	jsr tp_piece_collision
	cmp #TRUE
	bne :+
	lda #LOCK
	sta phase
	lda #60
	sta lock_timer
	lda piece_y
	sta lock_start_y
:
	rts
@pattern:
	lda phase
	cmp #PATTERN
	beq :+
	jmp @redraw
:	lda pattern_timer
	bne @pattern_frames
	lda inside_block
	beq :+
	lda traps_lines_counter
	cmp prev_traps_lines_counter
	bne :+
	lda #TRUE
	sta game_over
	lda #0
	sta game_over_fc
	rts
:	lda traps_lines_counter
	sta prev_traps_lines_counter
	lda #REDRAW
	sta phase
	rts
@pattern_frames:	
	cmp #10
	beq @10_frames
	cmp #6
	bcs @9_to_6_frames
	cmp #5
	beq @5_frames
	cmp #4
	beq @4_frames
	cmp #3
	beq @3_frames
	dec pattern_timer
	rts
@10_frames:	
	jsr tp_merge_piece_matrix
	jsr tp_clear_lines
	dec pattern_timer
	rts
@9_to_6_frames:	
	jsr tp_clear_traps
	inc clear_traps_frame
	lda #4
	cmp clear_traps_frame
	bne :+
	lda #0
	sta clear_traps_frame
:	dec pattern_timer
	rts
@5_frames:
	lda garbage_counter
	cmp #4
	bne :+
	jsr tp_get_random
	jsr tp_garbage_row
	lda #0
	sta garbage_counter
:	dec pattern_timer
	rts
@4_frames:
	jsr tp_calc_area
	jsr tp_calc_score
	dec pattern_timer
	rts
@3_frames:
	lda current_level
	cmp #6
	beq :++
	lda traps_lines_counter
	beq :+
	bpl :++
:	inc current_level
	lda #10
	sta traps_lines_counter
:	dec pattern_timer
	rts

@redraw:
	lda redraw_complete
	bne :++
	lda redraw_in_progress
	beq :+
	rts
:	lda swap_nametable
	eor #1
	asl
	asl
	sta tmp
	clc
	adc #>MATRIX_PPU_LOC
	sta matrix_ppu_loc+1
	lda tmp
	clc
	adc #>MATRIX_PPU_LOC_2
	sta matrix_ppu_loc_2+1
	lda tmp
	clc
	adc #>MATRIX_PPU_LOC_3
	sta matrix_ppu_loc_3+1
	lda tmp
	clc
	adc #>MATRIX_PPU_LOC_4
	sta matrix_ppu_loc_4+1
	lda #1
	sta redraw_in_progress
	lda #0
	sta redraw_frame
	rts
:	lda swap_nametable
	eor #1
	sta swap_nametable
	lda #GEN
	sta phase
	rts

tp_update_score:
	ldy #0
@loop:
	lda score,y
	cmp top_score,y
	beq @equal_digit
	bcs @greater_digit
	bcc @end
@equal_digit:	
	iny
	cpy #6
	beq @end
	jmp @loop
@greater_digit:	
	ldy #6
:	lda score,y
	sta top_score,y
	dey
	bne :-
@end:	
	lda #0
	ldy #6
:	sta score,y
	dey
	bne :-
	rts

tp_calc_score:
	ldx #0
	ldy amt_traps
	bne @loop
	rts
@loop:	
	inc score+3
	lda score+3
	cmp #10
	bne :+
	stx score+3
	inc score+2
	lda score+2
	cmp #10
	bne :+
	stx score+2
	inc score+1
	lda score+1
	cmp #10
	bne :+
	stx score+1
	inc score
:	dey
	bne @loop

	lda #0
	ldy size_traps
	bne @loop2
	rts
@loop2:
	inc score+5
	lda score+5
	cmp #10
	bne :+
	stx score+5
	inc score+4
	lda score+4
	cmp #10
	bne :+
	stx score+4
	inc score+3
	lda score+3
	cmp #10
	bne :+
	stx score+3
	inc score+2
	lda score+2
	cmp #10
	bne :+
	stx score+2
	inc score+1
	lda score+1
	cmp #10
	bne :+
	stx score+1
	inc score
:	dey
	bne @loop2
	rts

tp_garbage_row:
	lda #<(MATRIX+10)
	sta tmp
	lda #>(MATRIX+10)
	sta tmp+1
	lda #<MATRIX
	sta tmp2
	lda #>MATRIX
	sta tmp2+1
	ldx #1
	ldy #0
@loop:
	lda (tmp),y
	sta (tmp2),y
	iny
	cpy #10
	beq :+
	jmp @loop
:	ldy #0
	inx
	cpx #20
	beq :+
	lda tmp
	sta tmp2
	clc
	adc #10
	sta tmp
	lda tmp+1
	sta tmp2+1
	adc #0
	sta tmp+1
	jmp @loop
:	
@loop2:
	lda garbage_prev_row_mask,y
	eor #1
	and random,y
	sta (tmp),y
	iny
	lda random,y
	and #1
	dey
	sta garbage_prev_row_mask,y
	iny
	cpy #10
	beq :+
	jmp @loop2
:	
	rts

tp_merge_piece_matrix:
	lda #<MATRIX
	sta tmp
	lda #>MATRIX
	sta tmp+1
	; tmp : (x,y) as address in matrix
	; tmp4 : use-case
	lda piece_y
	asl
	sta tmp4
	asl
	asl
	clc
	adc tmp4
	adc tmp
	bcc :+
	inc tmp+1
:	tax
	clc
	adc piece_x
	sta tmp
	bcc :++
	lda piece_x
	bmi :+
	inc tmp+1
	jmp :++
:	cpx tmp
	bcs :+
	dec tmp+1
:	ldy #0
	ldx #0
@loop:	
	lda (piece_coll),y
	beq :+
	tya
	sta tmp4
	txa
	tay
	lda #1
	sta (tmp),y
	lda tmp4
	tay
:	inx
	iny
	cpy #3
	beq :+
	cpy #6
	beq :+
	cpy #9
	beq :++
	jmp @loop
:	txa
	clc
	adc #7
	tax
	jmp @loop
:	rts

tp_clear_traps:
.define	y_trap_end		tmp5
.define _phase			tmp3
.define y_before		tmp2+1
.define x_before		tmp3+1
.define tmp_before		tmp4+1
.define tmp_1_before	tmp5+1
.define	tmp6_before		tmp8
.define tmp6_1_before	tmp8+1
.define first_row		tmp4
.define y_trap			tmp7
.define y_this_loop		tmp2
.define x_end_frame		tmp7+1
	lda clear_traps_frame
	bne :+
	ldx #0
	lda #5
	sta x_end_frame
	lda #<MATRIX
	sta tmp
	lda #>MATRIX
	sta tmp+1
	lda #<TMP_MATRIX
	sta tmp6
	lda #>TMP_MATRIX
	sta tmp6+1
	lda #0
	sta amt_traps
	jmp @loop_start
:	cmp #1
	bne :+
	ldx #5
	lda #10
	sta x_end_frame
	lda #<MATRIX_2
	sta tmp
	lda #>MATRIX_2
	sta tmp+1
	lda #<TMP_MATRIX_2
	sta tmp6
	lda #>TMP_MATRIX_2
	sta tmp6+1
	jmp @loop_start
:	cmp #2
	bne :+
	ldx #10
	lda #15
	sta x_end_frame
	lda #<MATRIX_3
	sta tmp
	lda #>MATRIX_3
	sta tmp+1
	lda #<TMP_MATRIX_3
	sta tmp6
	lda #>TMP_MATRIX_3
	sta tmp6+1
	jmp @loop_start
:	ldx #15
	lda #20
	sta x_end_frame
	lda #<MATRIX_4
	sta tmp
	lda #>MATRIX_4
	sta tmp+1
	lda #<TMP_MATRIX_4
	sta tmp6
	lda #>TMP_MATRIX_4
	sta tmp6+1
@loop_start:	
	ldy #0
	sty _phase
	sty y_trap
@loop:
@phase_1:
	lda _phase
	beq :+
	jmp @phase_2
:
	; trap must have border on all sides
	; and begin with empty tile inside matrix
	; and be bordered on top, left
	cpx #0
	bne :+
	jmp @loop_end_alt
:	cpx #19
	bne :+
	jmp @loop_end_alt
:	cpy #0
	bne :+
	jmp @loop_end
:	cpy #9
	bne :+
	jmp @loop_end_alt
:	lda (tmp),y
	beq :+
	jmp @loop_end
:	dey
	lda (tmp),y
	bne :+
	iny
	jmp @loop_end
:	lda tmp+1
	sta tmp_1_before
	lda tmp
	sta tmp_before
	sec
	sbc #9
	sta tmp
	lda tmp+1
	sbc #0
	sta tmp+1
	lda (tmp),y
	bne :+
	lda tmp_before
	sta tmp
	lda tmp_1_before
	sta tmp+1
	iny
	jmp @loop_end
:
	; prep for phase 2
	lda tmp6
	sta tmp6_before
	lda tmp6+1
	sta tmp6_1_before
	iny
	sty y_this_loop
	sty y_before
	sty y_trap
	sty y_trap_end
	inc y_trap_end
	ldy amt_traps
	lda #0
	sta sizes_traps,y
	inc amt_traps
	ldy y_this_loop
	stx x_before
	lda #1
	sta _phase
	sta first_row
	lda tmp_before
	sta tmp
	lda tmp_1_before
	sta tmp+1

@phase_2:
	sty y_this_loop
	lda first_row
	beq :+
	jmp @phase_2b
:
	; change the trap left/right boundaries per new row
	cpy y_trap
	bne @not_left
	dey
	lda (tmp),y
	bne :+
	iny
	lda (tmp),y
	beq @trap_left_going_left
	jmp @trap_left_going_right
:	iny
	lda (tmp),y
	bne @trap_left_going_right
	jmp @phase_2b
@trap_left_going_right:
	; complete trap if row is all blocks
	iny
	cpy y_trap_end
	bne :+
	jmp @success
:	inc y_trap
	inc y_this_loop
	lda (tmp),y
	bne @trap_left_going_right
	jmp @phase_2b
@trap_left_going_left:
	dey
	lda tmp
	sec
	sbc #10
	sta tmp
	lda tmp+1
	sbc #0
	sta tmp+1
	lda (tmp),y
	bne :+
	jmp @meltdown
:	lda tmp
	clc
	adc #10
	sta tmp
	lda tmp+1
	adc #0
	sta tmp+1
	dec y_trap
	dec y_this_loop
	dey
	bpl :+
	jmp @meltdown
:	lda (tmp),y
	beq :+
	jmp @phase_2b
:	iny
	jmp @trap_left_going_left
@not_left:	
	cpy y_trap_end
	beq :+
	jmp @phase_2b
:	lda (tmp),y
	beq :+
	dey
	lda (tmp),y
	bne @trap_right_going_left
	jmp @loop_end_alt
:	dey
	lda (tmp),y
	beq @trap_right_going_right
@trap_right_going_left:
	lda (tmp),y
	bne :+
	jmp @loop_end_alt
:	dec y_trap_end
	dey
	jmp @trap_right_going_left
@trap_right_going_right:
	iny
	lda tmp
	sec
	sbc #10
	sta tmp
	lda tmp+1
	sbc #0
	sta tmp+1
	lda (tmp),y
	bne :+
	jmp @meltdown
:	lda tmp
	clc
	adc #10
	sta tmp
	lda tmp+1
	adc #0
	sta tmp+1
	iny
	cpy #10
	bne :+
	jmp @meltdown
:	inc y_trap_end
	lda (tmp),y
	beq :+
	jmp @phase_2b
:	dey
	jmp @trap_right_going_right

@phase_2b:
	ldy y_this_loop
	lda (tmp),y
	bne @block
	jmp @empty
@block:
	lda first_row
	beq @not_first_row
	jmp @end_first_row ; should remove block_check
	cpy #9
	bne :+
	jmp @end_first_row
:	txa
	asl
	sta tmp7+1
	asl
	asl
	clc
	adc tmp7+1
	sta tmp7+1
	lda #0
	sta _phase ; clobbers _phase
	lda tmp
	sec
	sbc #9
	sta tmp
	lda tmp+1
	sbc #0
	sta tmp+1
	lda (tmp),y
	ora _phase
	lda tmp
	clc
	adc #9
	sta tmp
	lda tmp+1
	adc #0
	sta tmp+1
	jmp @block_check
@not_first_row:	
	cpy y_trap_end
	bne :+
	jmp @loop_end_alt
:	jmp @loop_end
	; IGNORE ME
	; first row block tiles must have (y-1,x+n) and (y,x+n) empty
	; for one lowest n in range {1,19-x}
	; and there must be a block at one (y+1,x+(n-1)) or (y+1,x-1)
@block_check:
	iny
	lda (tmp),y
	ora _phase
	dey
	tya
	clc
	adc #10
	tay
	adc tmp7+1
	cmp #190
	bcs @end_first_row
	dey
	lda y_this_loop
	sec
	sbc y_trap
	cmp #1
	bne :+
	lda (tmp),y
	bne @end_first_row
	jmp :++
:	lda (tmp),y
	bne @block_check
:	iny
	lda (tmp),y
	bne @block_check
	lda _phase
	beq @end_first_row
@continue_first_row:
	lda #1
	sta _phase
	inc y_trap_end
	ldy y_this_loop
	jmp @loop_end
@end_first_row:
	lda #1
	sta _phase
	ldy y_this_loop
	lda #0
	sta first_row
	jmp @loop_end_alt

@empty:
	cpy #9
	bne :+
	jmp @meltdown
:	cpx #19
	bne :+
	jmp @meltdown
:	lda first_row
	beq @not_first_row_2
	cpy y_trap
	beq @not_first_row_2
	; empty tiles in first row must be covered on top (or behind: to-do)
	lda tmp
	sec
	sbc #10
	sta tmp
	lda tmp+1
	sbc #0
	sta tmp+1
	lda (tmp),y
	bne :+
	jmp @meltdown
:	lda tmp
	clc
	adc #10
	sta tmp
	lda tmp+1
	adc #0
	sta tmp+1
	inc y_trap_end
@not_first_row_2:
	; mark tile for removal
	; increment size of trap
	lda #1
	sta (tmp6),y
	ldy amt_traps
	dey
	lda sizes_traps,y
	clc
	adc #1
	sta sizes_traps,y
	ldy y_this_loop
	jmp @loop_end

@success:
	; merge tmp_matrix with mask_matrix
	lda #<TMP_MATRIX
	sta tmp6
	lda #>TMP_MATRIX
	sta tmp6+1
	lda #<MASK_MATRIX
	sta tmp
	lda #>MASK_MATRIX
	sta tmp+1
	ldy #190
:	dey
	lda (tmp6),y
	ora (tmp),y
	sta (tmp),y
	cpy #10
	bne :-
	dec traps_lines_counter
	jmp @complete_phase_2
@meltdown:
	; zero tmp_matrix
	lda #<TMP_MATRIX
	sta tmp6
	lda #>TMP_MATRIX
	sta tmp6+1
	ldy #190
	lda #0
:	dey
	sta (tmp6),y
	cpy #10
	bne :-
	dec amt_traps
@complete_phase_2:
	ldy y_before
	iny
	ldx x_before
	lda tmp_before
	sta tmp
	lda tmp_1_before
	sta tmp+1
	lda tmp6_before
	sta tmp6
	lda tmp6_1_before
	sta tmp6+1
	lda #0
	sta _phase
	sta y_trap
	jmp @loop

@loop_end:
	iny
	cpy #10
	beq :+
	jmp @loop
:
@loop_end_alt:
	ldy y_trap
	lda tmp
	clc
	adc #10
	sta tmp
	lda tmp+1
	adc #0
	sta tmp+1
	lda tmp6
	clc
	adc #10
	sta tmp6
	lda tmp6+1
	adc #0
	sta tmp6+1
	inx
	cpx x_end_frame
	beq :+
	jmp @loop
:	lda _phase
	beq :+
	jmp @loop
:
	lda clear_traps_frame
	cmp #3
	beq :+
	rts
:	; zero tmp_matrix
	lda #<TMP_MATRIX
	sta tmp
	lda #>TMP_MATRIX
	sta tmp+1
	lda #<(TMP_MATRIX-10)
	sta tmp2
	lda #>(TMP_MATRIX-10)
	sta tmp2+1
	lda #<(TMP_MATRIX+10)
	sta tmp3
	lda #>(TMP_MATRIX+10)
	sta tmp3+1
	ldy #190
	lda #0
:	dey
	sta (tmp),y
	cpy #10
	bne :-
	; fill tmp_matrix with modified mask_matrix
	lda #<MASK_MATRIX
	sta tmp4
	lda #>MASK_MATRIX
	sta tmp4+1
	ldy #190
@loop2:
	dey
	lda (tmp4),y
	beq :+
	dey
	sta (tmp),y
	sta (tmp2),y
	sta (tmp3),y
	iny
	sta (tmp2),y
	sta (tmp3),y
	iny
	sta (tmp),y
	sta (tmp2),y
	sta (tmp3),y
	dey
:	cpy #10
	bne @loop2
	; merge matrix with tmp_matrix
	; zero mask_matrix
	; zero tmp_matrix
	lda #<MATRIX
	sta tmp2
	lda #>MATRIX
	sta tmp2+1
	ldy #200
:	dey
	lda (tmp),y
	eor #1
	and (tmp2),y
	sta (tmp2),y
	lda #0
	sta (tmp),y
	sta (tmp4),y
	cpy #0
	bne :-
	rts
.undef	y_trap_end
.undef	_phase
.undef	y_before
.undef	x_before	
.undef	tmp_before
.undef	tmp_1_before
.undef	tmp6_before
.undef	tmp6_1_before
.undef	first_row
.undef	y_trap
.undef	y_this_loop
.undef	x_end_frame

tp_clear_lines:
	lda #<MATRIX
	sta tmp
	lda #>MATRIX
	sta tmp+1
	lda #0
	ldy #0
	ldx #0
@loop:
	clc
	adc (tmp),y
	iny
	cpy #10
	bne @loop
	cmp #10
	bne @endloop
	dec traps_lines_counter
	lda tmp
	sta tmp2
	sec
	sbc #10 
	sta tmp3
	lda tmp+1
	sta tmp2+1
	sbc #0
	sta tmp3+1
	ldy #0
@loop2:
	lda (tmp3),y
	sta (tmp2),y
	iny
	cpy #10
	bne @loop2
	ldy #0
	lda tmp3
	sta tmp2
	sec
	sbc #10
	sta tmp3
	lda tmp3+1
	sta tmp2+1
	sbc #0
	sta tmp3+1
	lda tmp3
	cmp #<MATRIX
	bcc @lobyte_less_matrix
@lobyte_greater_equals_matrix:
	lda tmp3+1
	cmp #>MATRIX
	bcs @loop2
	jmp @endloop
@lobyte_less_matrix:	
	lda tmp3+1
	cmp #>MATRIX
	beq @endloop
	bcc @endloop
	jmp @loop2
@endloop:	
	lda tmp
	clc
	adc #10
	sta tmp
	lda tmp+1
	adc #0
	sta tmp+1
	lda #0
	ldy #0
	inx
	cpx #20
	bne @loop
	rts

tp_piece_rotate:
; tmp		: direction (positive is clockwise)
	lda piece_coll
	pha
	lda piece_coll+1
	pha
	lda piece_rot
	pha

	lda tmp
	bmi @case_neg
@case_pos:
	lda piece_rot
	cmp #3
	bne @case_pos_012
	lda #0
	sta piece_rot
	lda piece_coll
	sec
	sbc #27
	sta piece_coll
	bcs :+
	dec piece_coll+1
:	jmp @check
@case_pos_012:	
	inc piece_rot
	lda piece_coll
	clc
	adc #9
	sta piece_coll
	bcc :+
	inc piece_coll+1
:	jmp @check
@case_neg:
	lda piece_rot
	bne @case_neg_123
	lda #3
	sta piece_rot
	lda piece_coll
	clc
	adc #27
	sta piece_coll
	bcc :+
	inc piece_coll+1
:	jmp @check
@case_neg_123:
	dec piece_rot
	lda piece_coll
	sec
	sbc #9
	sta piece_coll
	bcs :+
	dec piece_coll+1
:
@check:
	lda #0
	sta tmp3
	sta tmp3+1
	jsr tp_piece_collision
	cmp #TRUE
	bne :+
	pla
	sta piece_rot
	pla
	sta piece_coll+1
	pla
	sta piece_coll
	jmp :++
:	pla
	pla
	pla
:
	rts

tp_piece_collision:
; tmp3		: dx
; tmp3+1	: dy
	; store (x+dx,y+dy) in tmp3
	lda piece_y
	clc
	adc tmp3+1
	sta tmp3+1
	lda piece_x
	clc
	adc tmp3
	sta tmp3

	; bounds check
	lda tmp3+1
	cmp #20
	beq :+
	lda tmp3
	cmp #$fd
	beq :+
	cmp #10
	bne :++
:	lda #TRUE
	rts
:	
	; prep for collision check
	; tmp : tmp3 as address in matrix
	lda #<MATRIX
	sta tmp
	lda #>MATRIX
	sta tmp+1
	lda tmp3+1
	asl
	sta tmp4
	asl
	asl
	clc
	adc tmp4
	adc tmp
	bcc :+
	inc tmp+1
:	tax
	clc
	adc tmp3
	sta tmp
	bcc :++
	lda tmp3
	bmi :+
	inc tmp+1
	jmp :++
:	cpx tmp
	bcs :+
	dec tmp+1
:	; empty tiles of piece can leave bounds
	; tmp2+1 : first index when x+dx is outside matrix (9 if not)
	; tmp4+1 : how far x+dx is out of bounds
	; tmp5 : first index when y+dy is outside matrix ( | | )
	; tmp2 : makes x count 0,1,2,10,11,12 ...
	; tmp5+1 : makes y wait until next row once piece_x_out_bounds is complete
	; tmp4 : use-case
	lda #9
	sta tmp2+1
	sta tmp5
	lda tmp3
	bpl :+
	eor #$ff
	clc
	adc #1
	sta tmp2+1
	sta tmp4+1
	jmp :++
:	cmp #8
	bcc :+
	lda #10
	sec
	sbc tmp3
	sta tmp2+1
	lda #3
	sec
	sbc tmp2+1
	sta tmp4+1
:	lda tmp3+1
	cmp #18
	bcc :+
	lda #20
	sec
	sbc tmp3+1
	sta tmp5
	asl
	clc
	adc tmp5
	sta tmp5
:	ldy #0
	ldx #0
	stx tmp2
	stx tmp5+1
@loop:
	cpy tmp5
	bne @piece_y_in_bounds
@piece_y_out_bounds:	
	lda (piece_coll),y
	beq :+
	jmp @success
:	iny
	cpy #9
	bne @piece_y_out_bounds
	jmp @error
@piece_y_in_bounds:	
	cpy tmp5+1
	bcc @matrix_check
	lda tmp3
	bpl @piece_x_positive
	cpy tmp2+1
	bcc @piece_x_out_bounds
	jmp @matrix_check
@piece_x_positive:	
	cpy tmp2+1
	bcc @matrix_check
@piece_x_out_bounds:	
	lda #0
	sta tmp4
:	lda (piece_coll),y
	beq :+
	jmp @success
:	inx
	inc tmp2
	lda tmp2
	cmp #3
	bne :+
	txa
	clc
	adc #7
	tax
	lda #0
	sta tmp2
:	iny
	cpy #9
	beq @error
	inc tmp4
	lda tmp4
	cmp tmp4+1
	bne :---
	inc tmp2+1
	inc tmp2+1
	inc tmp2+1
	inc tmp5+1
	inc tmp5+1
	inc tmp5+1
	jmp @loop
@matrix_check:
	lda (piece_coll),y
	sta tmp4
	sty tmp6
	txa
	tay
	lda (tmp),y
	clc
	adc tmp4
	cmp #2
	bne @no_collision
	jmp @success
@no_collision:	
	inx
	inc tmp2
	lda tmp2
	cmp #3
	bne :+
	txa
	clc
	adc #7
	tax
	lda #0
	sta tmp2
:	ldy tmp6
	iny
	cpy #9
	beq @error
	jmp @loop
@error:
	lda #FALSE
	rts
@success:
	lda #TRUE
	rts

tp_new_piece_type:
	lda next_piece_type
	sta piece_type
	lda frame_counter
	and #15
	cmp #5
	bcc :+
	and #3
:	sta next_piece_type	
	rts

tp_piece_init:
	lda #<u_piece_coll
	sta piece_coll
	lda #>u_piece_coll
	sta piece_coll+1
	lda piece_type
	tax
@loop:	
	txa
	beq :+
	dex
	lda piece_coll
	clc
	adc #36
	sta piece_coll
	bcc @loop
	inc piece_coll+1
	jmp @loop
:	lda #0
	sta piece_rot
	sta piece_y
	lda #3
	sta piece_x
	rts

tp_frame_screen:
	lda screen
@title:
	cmp #TITLE
	bne @menu
	rts
@menu:
	cmp #MENU
	beq :+
	jmp @level
:	jsr tp_draw_menu_0_select
	jsr tp_draw_menu_1_select
	jsr tp_draw_menu_bars
	rts
@level:
	lda game_over
	beq :+
	jsr tp_draw_game_over
:
	ldx #0
	lda paused
	beq :+
	ldx #$e0
:	stx emphasis_bits

	jsr tp_draw_piece

	lda redraw_complete
	beq :+
	lda #0
	sta redraw_complete
:	lda redraw_in_progress
	bne :+
	rts
:	inc redraw_frame ; starts on one to save cycles
	lda redraw_frame
	cmp #5
	beq :+
	bcs :++
	jsr tp_draw_matrix
	rts
:	cmp #5
	bne :+
	lda swap_nametable
	eor #1
	asl
	asl
	clc
	adc #$20
	sta tmp5
	lda #<score
	sta tmp
	lda #>score
	sta tmp+1
	lda #7
	sta tmp2
	lda #25
	sta tmp2+1
	lda #$70
	sta tmp4
	jsr tp_draw_score
	rts
:	cmp #6
	bne :+
	lda swap_nametable
	eor #1
	asl
	asl
	clc
	adc #$20
	sta tmp5
	jsr tp_new_piece_type
	jsr tp_draw_next_piece
	rts
:	cmp #7
	bne :+
	lda swap_nametable
	eor #1
	asl
	asl
	clc
	adc #$20
	sta tmp5
	jsr tp_draw_area
	rts
:	cmp #8
	bne :+
	lda swap_nametable
	eor #1
	asl
	asl
	clc
	adc #$20
	sta tmp5
	lda #<top_score
	sta tmp
	lda #>top_score
	sta tmp+1
	lda #23
	sta tmp2
	lda #25
	sta tmp2+1
	lda #$80
	sta tmp4
	jsr tp_draw_score
	rts
:	cmp #9
	bne :+
	lda #1
	sta redraw_complete
	lda #0
	sta redraw_in_progress
	sta redraw_frame
:	rts

tp_draw_game_over:
	lda game_over_fc
	bne @175_frames
	lda swap_nametable
	asl
	asl
	clc
	adc #$20
	sta tmp5
	lda #<txt_game_over
	sta tmp
	lda #>txt_game_over
	sta tmp+1
	lda #11
	sta tmp2
	lda #1
	sta tmp2+1
	jsr draw_text
	rts
@175_frames:	
	cmp #175
	bne @180_frames
	lda #0
	sta PPU_CTRL
	bit PPU_STATUS
	lda swap_nametable
	asl
	asl
	clc
	adc #$20
	sta PPU_ADDR
	lda #$2b
	sta PPU_ADDR
	lda #SPACE
	ldy #10
:	sta PPU_DATA
	dey
	bne :-
	rts
@180_frames:
	cmp #180
	bne @end
	lda swap_nametable
	asl
	asl
	clc
	adc #$20
	sta tmp5
	lda #<txt_press_start_2
	sta tmp
	lda #>txt_press_start_2
	sta tmp+1
	lda #10
	sta tmp2
	lda #1
	sta tmp2+1
	jsr draw_text
	rts
@end:	
	rts

tp_draw_menu_0_select:
	bit PPU_STATUS
	lda prev_menu_0_ppu_addr+1
	sta PPU_ADDR
	lda prev_menu_0_ppu_addr
	sta PPU_ADDR
	lda #SPACE
	sta PPU_DATA

	lda #0
	ldy current_level
	beq :++
:	clc
	adc #2
	dey
	bne :-
:	clc
	adc #$8a
	sta tmp3
	sta prev_menu_0_ppu_addr
	lda #$21
	adc #0
	sta tmp3+1
	sta prev_menu_0_ppu_addr+1

	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	lda #ARROW_UP
	sta PPU_DATA
	rts

tp_draw_menu_1_select:
	bit PPU_STATUS
	lda prev_menu_1_ppu_addr+1
	sta PPU_ADDR
	lda prev_menu_1_ppu_addr
	sta PPU_ADDR
	lda #SPACE
	sta PPU_DATA

	lda #0
	ldy music_select
	beq :+
	clc
	adc #10
:	clc
	adc #$09
	sta tmp3
	sta prev_menu_1_ppu_addr
	lda #$22
	adc #0
	sta tmp3+1
	sta prev_menu_1_ppu_addr+1

	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	lda #ARROW_RIGHT
	sta PPU_DATA
	rts

tp_draw_menu_bars:
	ldx #SPACE
	lda #0
	sta PPU_CTRL
	bit PPU_STATUS
	lda prev_menu_bar_0_ppu_addr+1
	sta PPU_ADDR
	lda prev_menu_bar_0_ppu_addr
	sta PPU_ADDR
	ldy #22
:	stx PPU_DATA
	dey
	bne :-
	bit PPU_STATUS
	lda prev_menu_bar_1_ppu_addr+1
	sta PPU_ADDR
	lda prev_menu_bar_1_ppu_addr
	sta PPU_ADDR
	ldy #22
:	stx PPU_DATA
	dey
	bne :-

	lda menu_select
	asl
	tay
	lda menu_bar_0_ppu_addr,y
	sta tmp3
	sta prev_menu_bar_0_ppu_addr
	lda menu_bar_0_ppu_addr+1,y
	sta tmp3+1
	sta prev_menu_bar_0_ppu_addr+1
	lda menu_bar_1_ppu_addr,y
	sta tmp4
	sta prev_menu_bar_1_ppu_addr
	lda menu_bar_1_ppu_addr+1,y
	sta tmp4+1
	sta prev_menu_bar_1_ppu_addr+1
	
	ldx #BAR
	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	ldy #22
:	stx PPU_DATA
	dey
	bne :-
	bit PPU_STATUS
	lda tmp4+1
	sta PPU_ADDR
	lda tmp4
	sta PPU_ADDR
	ldy #22
:	stx PPU_DATA
	dey
	bne :-

	rts

tp_draw_area:
; tmp5	: nametable high byte
	lda #$4a
	sta tmp3
	lda #$03
	clc
	adc tmp5
	sta tmp3+1
	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	lda #0
	sta PPU_CTRL

	lda size_traps
	bne :+
	lda #$27
	sta PPU_DATA
	lda #DASH
	sta PPU_DATA
	sta PPU_DATA
	rts
:	lda area
	bne :+
	lda #$27
	jmp :++
:	ora #$70
:	sta PPU_DATA
	lda area+1
	ora #$70
	sta PPU_DATA
	lda area+2
	ora #$70
	sta PPU_DATA
	rts

tp_calc_area:
	ldy amt_traps
	bne :+
	rts
:	lda #0
	sta area+2
	sta area+1
	sta area
@loop:
	dey
	clc
	adc sizes_traps,y
	cpy #0
	bne @loop
	sta size_traps
	tay
	ldx #0
@loop2:
	inc area+2
	lda area+2
	cmp #10
	bne :+
	stx area+2
	inc area+1
	lda area+1
	cmp #10
	bne :+
	stx area+1
	inc area+2
:	dey
	bne @loop2
	rts

tp_draw_piece:
	ldy #0
	sty tmp
	sty tmp2
	lda piece_y
	clc
	adc #MATRIX_Y
	asl
	asl
	asl
	sec
	sbc #1
	tax
	lda piece_x
	clc
	adc #MATRIX_X
	asl
	asl
	asl
@loop:	
	pha
	tya
	pha
	ldy tmp2
	lda (piece_coll),y
	bne :+
	pla
	tay
	lda #SPACE
	sta SPR_DMA+1,y
	jmp :++
:	pla
	tay
	lda #BLOCK
	sta SPR_DMA+1,y
:	pla

	sta SPR_DMA+3,y
	pha
	txa
	sta SPR_DMA,y
	pla
	clc
	adc #8
	pha
	inc tmp
	lda tmp
	cmp #3
	bne :+
	lda #0
	sta tmp
	txa
	clc
	adc #8
	tax
	pla
	sec
	sbc #24
	jmp :++
:	pla
:	inc tmp2
	iny
	iny
	iny
	iny
	cpy #36
	bne @loop
	rts

tp_init_var:
	lda #TITLE
	sta screen
	lda #LEVEL
	sta lastscreen
	lda #93
	ldy #0
@loop:
	sta random,y
	clc
	adc #10
	iny
	cpy #10
	beq :+
	jmp @loop
:	jsr tp_get_random
	lda #1
	sta top_score+1
	rts

tp_get_random:
	ldy #0
@loop:
	lda random,y
	asl
	sta random,y
	and #80
	beq :+
	lda #1
:	sta tmp
	lda #0
	adc #0
	eor tmp
	ora random,y
	sta random,y
	iny
	cpy #10
	beq :+
	jmp @loop
:	rts

tp_init_screen:
	inc init_screen_frame
	lda screen
	cmp #TITLE
	bne @menu
@title:
	lda init_screen_frame
	cmp #1
	bne @frame_2
@frame_1:
	lda #<title_palette
	sta tmp
	lda #>title_palette
	sta tmp+1
	jsr load_palette
	lda #SPACE
	sta tmp
	jsr clear_nametables
	jsr clear_attrib
	jsr hide_sprites
	jsr tp_draw_title
	rts
@frame_2:
	lda #0
	sta init_screen_frame
	lda #$ff
	sta rendering_on
	rts
@menu:
	cmp #MENU
	bne @level
	lda init_screen_frame
	cmp #1
	bne @fframe_2
@fframe_1:
	lda #<menu_palette
	sta tmp
	lda #>menu_palette
	sta tmp+1
	jsr load_palette
	lda #SPACE
	sta tmp
	lda #0
	jsr clear_nametables
	jsr clear_attrib
	jsr hide_sprites
	jsr tp_draw_menu
	lda #$8a
	sta prev_menu_0_ppu_addr
	lda #$21
	sta prev_menu_0_ppu_addr+1
	lda #$09
	sta prev_menu_1_ppu_addr
	lda #$22
	sta prev_menu_1_ppu_addr+1
	lda menu_bar_0_ppu_addr+1
	sta prev_menu_bar_0_ppu_addr+1
	lda menu_bar_0_ppu_addr
	sta prev_menu_bar_0_ppu_addr
	lda menu_bar_1_ppu_addr+1
	sta prev_menu_bar_0_ppu_addr+1
	lda menu_bar_1_ppu_addr
	sta prev_menu_bar_0_ppu_addr
	rts
@fframe_2:
	lda #0
	sta init_screen_frame
	lda #$ff
	sta rendering_on
	rts
@level:
	lda init_screen_frame
	cmp #1
	bne @ffframe_2
@ffframe_1:
	lda #SPACE
	sta tmp
	jsr clear_nametables
	jsr clear_attrib
	jsr hide_sprites
	rts
@ffframe_2:
	cmp #2
	bne @ffframe_3
	lda game_over
	beq :+
	jsr tp_clear_matrix
	lda #0
	sta garbage_counter
	sta size_traps
	sta garbage_prev_row_mask
	sta game_over
:	jsr tp_draw_level_0
	rts
@ffframe_3:
	cmp #3
	bne @ffframe_4
	jsr tp_draw_level_1
	rts
@ffframe_4:
	cmp #4
	bne @ffframe_5
	jsr tp_draw_level_2
	ldy current_level
	lda level_requirement,y
	sta traps_lines_counter
	sta prev_traps_lines_counter
	lda #GEN
	sta phase
	rts
@ffframe_5:
	lda #<level_palette
	sta tmp
	lda #>level_palette
	sta tmp+1
	jsr load_palette
	lda #0
	sta init_screen_frame
	lda #$ff
	sta rendering_on
	rts

tp_clear_matrix:
	lda #0
	ldy #200
:	dey
	sta MATRIX,y
	bne :-
	rts

tp_draw_menu:
	lda #$20
	sta tmp5

	lda #<txt_level
	sta tmp
	lda #>txt_level
	sta tmp+1
	lda #9
	sta tmp2
	lda #10
	sta tmp2+1
	jsr draw_text
	lda #<txt_level_settings
	sta tmp
	lda #>txt_level_settings
	sta tmp+1
	lda #10
	sta tmp2
	lda #11
	sta tmp2+1
	jsr draw_text
	lda #<txt_music
	sta tmp
	lda #>txt_music
	sta tmp+1
	lda #9
	sta tmp2
	lda #15
	sta tmp2+1
	jsr draw_text
	lda #<txt_baroque_rus
	sta tmp
	lda #>txt_baroque_rus
	sta tmp+1
	lda #11
	sta tmp2
	lda #16
	sta tmp2+1
	jsr draw_text
	lda #<txt_to_game
	sta tmp
	lda #>txt_to_game
	sta tmp+1
	lda #9
	sta tmp2
	lda #20
	sta tmp2+1
	jsr draw_text
	rts

tp_draw_level_0:
	lda #<MATRIX_PPU_LOC
	sta matrix_ppu_loc
	lda #<MATRIX_PPU_LOC_2
	sta matrix_ppu_loc_2
	lda #<MATRIX_PPU_LOC_3
	sta matrix_ppu_loc_3
	lda #<MATRIX_PPU_LOC_4
	sta matrix_ppu_loc_4
	lda #>MATRIX_PPU_LOC
	sta matrix_ppu_loc+1
	lda #>MATRIX_PPU_LOC_2
	sta matrix_ppu_loc_2+1
	lda #>MATRIX_PPU_LOC_3
	sta matrix_ppu_loc_3+1
	lda #>MATRIX_PPU_LOC_4
	sta matrix_ppu_loc_4+1
	inc redraw_frame
	jsr tp_draw_matrix
	inc redraw_frame
	jsr tp_draw_matrix
	inc redraw_frame
	jsr tp_draw_matrix
	inc redraw_frame
	jsr tp_draw_matrix
	lda #0
	sta redraw_frame
	rts

tp_draw_level_1:
	lda #$20
	sta tmp5

	lda #<img_column_0
	sta tmp
	lda #>img_column_0
	sta tmp+1
	lda #0
	sta tmp2
	lda #2
	sta tmp2+1
	jsr draw_vertical_image
	lda #<img_column_1
	sta tmp
	lda #>img_column_1
	sta tmp+1
	lda #14
	sta tmp2
	lda #2
	sta tmp2+1
	jsr draw_vertical_image
	lda #<img_column_2
	sta tmp
	lda #>img_column_2
	sta tmp+1
	lda #30
	sta tmp2
	lda #2
	sta tmp2+1
	jsr draw_vertical_image
	lda #<img_card
	sta tmp
	lda #>img_card
	sta tmp+1
	lda #18
	sta tmp2
	lda #4
	sta tmp2+1
	jsr draw_vertical_image
	lda #<img_matrix_top
	sta tmp
	lda #>img_matrix_top
	sta tmp+1
	lda #2
	sta tmp2
	lda #2
	sta tmp2+1
	jsr draw_horizontal_image
	lda #$27
	sta tmp
	lda #2
	sta tmp2
	lda #5
	sta tmp2+1
	lda #20
	sta tmp4
	jsr draw_column
	lda #13
	sta tmp2
	jsr draw_column
	lda #<img_matrix_bottom
	sta tmp
	lda #>img_matrix_bottom
	sta tmp+1
	lda #2
	sta tmp2
	lda #25
	sta tmp2+1
	jsr draw_horizontal_image
	lda #<img_card_top
	sta tmp
	lda #>img_card_top
	sta tmp+1
	lda #18
	sta tmp2
	lda #2
	sta tmp2+1
	jsr draw_horizontal_image
	lda #<img_card_bottom
	sta tmp
	lda #>img_card_bottom
	sta tmp+1
	lda #18
	sta tmp2
	lda #24
	sta tmp2+1
	jsr draw_horizontal_image
	lda #<attrib_card
	sta tmp
	lda #>attrib_card
	sta tmp+1
	lda #4
	sta tmp2
	lda #1
	sta tmp2+1
	jsr attribute_rect
	lda #<score
	sta tmp
	lda #>score
	sta tmp+1
	lda #7
	sta tmp2
	lda #25
	sta tmp2+1
	lda #$70
	sta tmp4
	jsr tp_draw_score
	lda #<top_score
	sta tmp
	lda #>top_score
	sta tmp+1
	lda #23
	sta tmp2
	lda #25
	sta tmp2+1
	lda #$80
	sta tmp4
	jsr tp_draw_score
	jsr tp_new_piece_type
	jsr tp_new_piece_type
	jsr tp_draw_next_piece
	jsr tp_piece_init
	jsr tp_draw_piece
	bit PPU_STATUS
	lda #$23
	sta PPU_ADDR
	lda #$4b
	sta PPU_ADDR
	lda #DASH
	sta PPU_DATA
	sta PPU_DATA
	rts

tp_draw_level_2:
	lda #$24
	sta tmp5
	
	lda #<img_column_0
	sta tmp
	lda #>img_column_0
	sta tmp+1
	lda #0
	sta tmp2
	lda #2
	sta tmp2+1
	jsr draw_vertical_image
	lda #<img_column_1
	sta tmp
	lda #>img_column_1
	sta tmp+1
	lda #14
	sta tmp2
	lda #2
	sta tmp2+1
	jsr draw_vertical_image
	lda #<img_column_2
	sta tmp
	lda #>img_column_2
	sta tmp+1
	lda #30
	sta tmp2
	lda #2
	sta tmp2+1
	jsr draw_vertical_image
	lda #<img_card
	sta tmp
	lda #>img_card
	sta tmp+1
	lda #18
	sta tmp2
	lda #4
	sta tmp2+1
	jsr draw_vertical_image
	lda #<img_matrix_top
	sta tmp
	lda #>img_matrix_top
	sta tmp+1
	lda #2
	sta tmp2
	lda #2
	sta tmp2+1
	jsr draw_horizontal_image
	lda #$27
	sta tmp
	lda #2
	sta tmp2
	lda #5
	sta tmp2+1
	lda #20
	sta tmp4
	jsr draw_column
	lda #13
	sta tmp2
	jsr draw_column
	lda #<img_matrix_bottom
	sta tmp
	lda #>img_matrix_bottom
	sta tmp+1
	lda #2
	sta tmp2
	lda #25
	sta tmp2+1
	jsr draw_horizontal_image
	lda #<img_card_top
	sta tmp
	lda #>img_card_top
	sta tmp+1
	lda #18
	sta tmp2
	lda #2
	sta tmp2+1
	jsr draw_horizontal_image
	lda #<img_card_bottom
	sta tmp
	lda #>img_card_bottom
	sta tmp+1
	lda #18
	sta tmp2
	lda #24
	sta tmp2+1
	jsr draw_horizontal_image
	lda #<attrib_card
	sta tmp
	lda #>attrib_card
	sta tmp+1
	lda #4
	sta tmp2
	lda #1
	sta tmp2+1
	jsr attribute_rect

	rts

tp_draw_matrix:
	lda #4
	sta PPU_CTRL
	lda redraw_frame
	cmp #2
	bne :+
	jmp @loop1_start
:	cmp #3
	bne :+
	jmp @loop2_start
:	cmp #4
	bne @loop_start
	jmp @loop3_start
@loop_start:
	lda matrix_ppu_loc
	clc
	adc #9
	tay
	ldx #9
@loop:
	bit PPU_STATUS
	lda matrix_ppu_loc+1
	sta PPU_ADDR
	sty PPU_ADDR
	lda MATRIX,x
	sta PPU_DATA
	lda MATRIX+10,x
	sta PPU_DATA
	lda MATRIX+20,x
	sta PPU_DATA
	lda MATRIX+30,x
	sta PPU_DATA
	lda MATRIX+40,x
	sta PPU_DATA
	dey
	dex
	bmi :+
	jmp @loop
:	rts
@loop1_start:
	lda matrix_ppu_loc_2
	clc
	adc #9
	tay
	ldx #9
@loop1:
	bit PPU_STATUS
	lda matrix_ppu_loc_2+1
	sta PPU_ADDR
	sty PPU_ADDR
	lda MATRIX+50,x
	sta PPU_DATA
	lda MATRIX+60,x
	sta PPU_DATA
	lda MATRIX+70,x
	sta PPU_DATA
	lda MATRIX+80,x
	sta PPU_DATA
	lda MATRIX+90,x
	sta PPU_DATA
	dey
	dex
	bmi :+
	jmp @loop1
:	rts
@loop2_start:
	lda matrix_ppu_loc_3
	clc
	adc #9
	tay
	ldx #9
@loop2:
	bit PPU_STATUS
	lda matrix_ppu_loc_3+1
	sta PPU_ADDR
	sty PPU_ADDR
	lda MATRIX+100,x
	sta PPU_DATA
	lda MATRIX+110,x
	sta PPU_DATA
	lda MATRIX+120,x
	sta PPU_DATA
	lda MATRIX+130,x
	sta PPU_DATA
	lda MATRIX+140,x
	sta PPU_DATA
	dey
	dex
	bmi :+
	jmp @loop2
:	rts
@loop3_start:
	lda matrix_ppu_loc_4
	clc
	adc #9
	tay
	ldx #9
@loop3:
	bit PPU_STATUS
	lda matrix_ppu_loc_4+1
	sta PPU_ADDR
	sty PPU_ADDR
	lda MATRIX+150,x
	sta PPU_DATA
	lda MATRIX+160,x
	sta PPU_DATA
	lda MATRIX+170,x
	sta PPU_DATA
	lda MATRIX+180,x
	sta PPU_DATA
	lda MATRIX+190,x
	sta PPU_DATA
	dey
	dex
	bmi :+
	jmp @loop3
:	rts

tp_draw_title:
	lda #$20
	sta tmp5

	lda #<txt_copy
	sta tmp
	lda #>txt_copy
	sta tmp+1
	lda #3
	sta tmp2
	lda #24
	sta tmp2+1
	jsr draw_text
	lda #<txt_press_start
	sta tmp
	lda #>txt_press_start
	sta tmp+1
	lda #6
	sta tmp2
	lda #25
	sta tmp2+1
	jsr draw_text
	lda #<img_trap
	sta tmp
	lda #>img_trap
	sta tmp+1
	lda #4
	sta tmp2
	lda #4
	sta tmp2+1
	jsr draw_horizontal_image
	lda #<img_puzzle
	sta tmp
	lda #>img_puzzle
	sta tmp+1
	lda #4
	sta tmp2
	lda #10
	sta tmp2+1
	jsr draw_horizontal_image
	lda #<txt_marathon
	sta tmp
	lda #>txt_marathon
	sta tmp+1
	lda #12
	sta tmp2
	lda #18
	sta tmp2+1
	jsr draw_text
	bit PPU_STATUS
	lda #$22
	sta PPU_ADDR
	lda #$49
	sta PPU_ADDR
	lda #BLOCK
	sta PPU_DATA
	rts

tp_draw_next_piece:
; tmp5	: nametable high byte
	; store piece collision mask + 3 in x
	lda next_piece_type
	ldx #0
	tay
:	tya
	beq :+
	txa
	clc
	adc #6
	tax
	dey
	jmp :-
:	
	lda #103  ; 7+3*32
	sta tmp3
	lda tmp5
	sta tmp3+1
	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	lda #0
	sta PPU_CTRL
@loop:	
	lda u_piece_next,x
	beq :+
	lda #$8d
:	sta PPU_DATA
	inx
	iny
	cpy #3
	bne :+
	lda tmp3
	clc
	adc #32
	sta tmp3
	bit PPU_STATUS
	lda tmp3+1
	sta PPU_ADDR
	lda tmp3
	sta PPU_ADDR
	jmp @loop
:	cpy #6
	bne @loop
	rts

tp_draw_score:
; tmp	: score (bcd) address
; tmp2	: xpos
; tmp2+1: ypos
; tmp5	: nametable high byte
; tmp4	: tileset shift byte
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
@loop:
	lda (tmp),y
	ora tmp4
	sta PPU_DATA
	iny
	cpy #6
	bne @loop
	rts


