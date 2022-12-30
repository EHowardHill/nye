#ifndef BN_SPRITE_ITEMS_GRASS_H
#define BN_SPRITE_ITEMS_GRASS_H

#include "bn_sprite_item.h"

//{{BLOCK(grass_bn_gfx)

//======================================================================
//
//	grass_bn_gfx, 64x128@4, 
//	+ palette 16 entries, not compressed
//	+ 128 tiles not compressed
//	Total size: 32 + 4096 = 4128
//
//	Time-stamp: 2022-12-30, 03:37:54
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GRASS_BN_GFX_H
#define GRIT_GRASS_BN_GFX_H

#define grass_bn_gfxTilesLen 4096
extern const bn::tile grass_bn_gfxTiles[128];

#define grass_bn_gfxPalLen 32
extern const bn::color grass_bn_gfxPal[16];

#endif // GRIT_GRASS_BN_GFX_H

//}}BLOCK(grass_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item grass(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(grass_bn_gfxTiles, 128), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(grass_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

