#ifndef BN_SPRITE_ITEMS_TREES01_H
#define BN_SPRITE_ITEMS_TREES01_H

#include "bn_sprite_item.h"

//{{BLOCK(trees01_bn_gfx)

//======================================================================
//
//	trees01_bn_gfx, 64x256@4, 
//	+ palette 16 entries, not compressed
//	+ 256 tiles not compressed
//	Total size: 32 + 8192 = 8224
//
//	Time-stamp: 2022-12-30, 03:17:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TREES01_BN_GFX_H
#define GRIT_TREES01_BN_GFX_H

#define trees01_bn_gfxTilesLen 8192
extern const bn::tile trees01_bn_gfxTiles[256];

#define trees01_bn_gfxPalLen 32
extern const bn::color trees01_bn_gfxPal[16];

#endif // GRIT_TREES01_BN_GFX_H

//}}BLOCK(trees01_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item trees01(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(trees01_bn_gfxTiles, 256), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(trees01_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

