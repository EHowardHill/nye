#ifndef BN_SPRITE_ITEMS_SPARKLE_H
#define BN_SPRITE_ITEMS_SPARKLE_H

#include "bn_sprite_item.h"

//{{BLOCK(sparkle_bn_gfx)

//======================================================================
//
//	sparkle_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2022-12-30, 03:48:22
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SPARKLE_BN_GFX_H
#define GRIT_SPARKLE_BN_GFX_H

#define sparkle_bn_gfxTilesLen 32
extern const bn::tile sparkle_bn_gfxTiles[1];

#define sparkle_bn_gfxPalLen 32
extern const bn::color sparkle_bn_gfxPal[16];

#endif // GRIT_SPARKLE_BN_GFX_H

//}}BLOCK(sparkle_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item sparkle(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(sparkle_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(sparkle_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

