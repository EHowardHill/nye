
@{{BLOCK(sparkle_bn_gfx)

@=======================================================================
@
@	sparkle_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2022-12-30, 03:48:22
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global sparkle_bn_gfxTiles		@ 32 unsigned chars
	.hidden sparkle_bn_gfxTiles
sparkle_bn_gfxTiles:
	.word 0x00043000,0x00275000,0x028CC800,0x26BEEB62,0x26ADDA53,0x02799710,0x00266000,0x00012000

	.section .rodata
	.align	2
	.global sparkle_bn_gfxPal		@ 32 unsigned chars
	.hidden sparkle_bn_gfxPal
sparkle_bn_gfxPal:
	.hword 0x69CD,0x69EE,0x69EE,0x6A0F,0x6A30,0x6E72,0x6E93,0x6E93
	.hword 0x72F6,0x7739,0x775A,0x7B7A,0x7B9B,0x7FDF,0x7FFE,0x0000

@}}BLOCK(sparkle_bn_gfx)
