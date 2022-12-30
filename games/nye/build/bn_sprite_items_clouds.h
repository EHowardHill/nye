#ifndef BN_SPRITE_ITEMS_CLOUDS_H
#define BN_SPRITE_ITEMS_CLOUDS_H

#include "bn_sprite_item.h"

//{{BLOCK(clouds_bn_gfx)

//======================================================================
//
//	clouds_bn_gfx, 64x256@4, 
//	+ palette 16 entries, not compressed
//	+ 256 tiles not compressed
//	Total size: 32 + 8192 = 8224
//
//	Time-stamp: 2022-12-30, 02:27:41
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CLOUDS_BN_GFX_H
#define GRIT_CLOUDS_BN_GFX_H

#define clouds_bn_gfxTilesLen 8192
extern const bn::tile clouds_bn_gfxTiles[256];

#define clouds_bn_gfxPalLen 32
extern const bn::color clouds_bn_gfxPal[16];

#endif // GRIT_CLOUDS_BN_GFX_H

//}}BLOCK(clouds_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item clouds(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(clouds_bn_gfxTiles, 256), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(clouds_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

