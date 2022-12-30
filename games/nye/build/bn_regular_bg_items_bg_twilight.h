#ifndef BN_REGULAR_BG_ITEMS_BG_TWILIGHT_H
#define BN_REGULAR_BG_ITEMS_BG_TWILIGHT_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg_twilight_bn_gfx)

//======================================================================
//
//	bg_twilight_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 604 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 19328 + 2048 = 21408
//
//	Time-stamp: 2022-12-30, 02:32:25
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_TWILIGHT_BN_GFX_H
#define GRIT_BG_TWILIGHT_BN_GFX_H

#define bg_twilight_bn_gfxTilesLen 19328
extern const bn::tile bg_twilight_bn_gfxTiles[604];

#define bg_twilight_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell bg_twilight_bn_gfxMap[1024];

#define bg_twilight_bn_gfxPalLen 32
extern const bn::color bg_twilight_bn_gfxPal[16];

#endif // GRIT_BG_TWILIGHT_BN_GFX_H

//}}BLOCK(bg_twilight_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg_twilight(
            regular_bg_tiles_item(span<const tile>(bg_twilight_bn_gfxTiles, 604), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(bg_twilight_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(bg_twilight_bn_gfxMap[0], size(32, 32), compression_type::NONE));
}

#endif

