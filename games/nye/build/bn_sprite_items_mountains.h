#ifndef BN_SPRITE_ITEMS_MOUNTAINS_H
#define BN_SPRITE_ITEMS_MOUNTAINS_H

#include "bn_sprite_item.h"

//{{BLOCK(mountains_bn_gfx)

//======================================================================
//
//	mountains_bn_gfx, 64x256@4, 
//	+ palette 16 entries, not compressed
//	+ 256 tiles not compressed
//	Total size: 32 + 8192 = 8224
//
//	Time-stamp: 2022-12-30, 02:59:42
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MOUNTAINS_BN_GFX_H
#define GRIT_MOUNTAINS_BN_GFX_H

#define mountains_bn_gfxTilesLen 8192
extern const bn::tile mountains_bn_gfxTiles[256];

#define mountains_bn_gfxPalLen 32
extern const bn::color mountains_bn_gfxPal[16];

#endif // GRIT_MOUNTAINS_BN_GFX_H

//}}BLOCK(mountains_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item mountains(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(mountains_bn_gfxTiles, 256), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(mountains_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

