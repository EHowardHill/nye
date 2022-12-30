/*
    Cornucopia, by Ethan Hill
    Joey Hurguth tweaked some bits and made it more fun though

    License for Butano:

    Copyright (c) 2020-2022 Gustavo Valiente gustavo.valiente@protonmail.com
    zlib License, see LICENSE file.
*/

// Butano libraries
#include "bn_core.h"
#include "bn_log.h"
#include "bn_sram.h"
#include "bn_music.h"
#include "bn_music_actions.h"
#include "bn_music_items.h"
// #include "bn_sound_items.h"
#include "bn_rect_window_actions.h"
#include "bn_rect_window_boundaries_hbe_ptr.h"
#include "bn_sram.h"
#include "bn_math.h"
#include "bn_cstring.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_random.h"
#include "bn_blending.h"
#include "bn_bg_palettes.h"
#include "bn_bg_palette_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_palette_ptr.h"
#include "common_info.h"
#include "common_variable_8x8_sprite_font.h"

// My assets
#include "bn_sprite_items_clouds.h"
#include "bn_sprite_items_mountains.h"
#include "bn_sprite_items_trees01.h"
#include "bn_sprite_items_grass.h"
#include "bn_sprite_items_sparkle.h"

// Backgrounds
#include "bn_regular_bg_items_bg_twilight.h"
#include "bn_regular_bg_items_bg_grass.h"

#define IWRAM_CODE __attribute__((section(".iwram.text"), long_call))
#define EWRAM_CODE __attribute__((section(".ewram.text"), long_call))
#define IWRAM_DATA __attribute__((section(".iwram.data")))
#define EWRAM_DATA __attribute__((section(".ewram.data")))

#define lerp(a, b, t) (a * (1 - t) + b * t)

int main()
{
    // Initialization
    bn::core::init();

    unsigned int ticker = 0;
    bn::random rnd;

    auto bg_sky = bn::regular_bg_items::bg_twilight.create_bg(0, 0);
    auto bg_grass = bn::regular_bg_items::bg_grass.create_bg(0, 24);
    bn::music_items::arirang.play(0.5);

    bn::sprite_ptr clouds[6] = {
        bn::sprite_items::clouds.create_sprite(-80, -32, 1),
        bn::sprite_items::clouds.create_sprite(-80 + 64, -32, 0),
        bn::sprite_items::clouds.create_sprite(80, -24, 3),
        bn::sprite_items::clouds.create_sprite(80 + 64, -24, 2),
        bn::sprite_items::clouds.create_sprite(-70, 48, 3),
        bn::sprite_items::clouds.create_sprite(-70 + 32, 48, 2)};

    bn::sprite_ptr mountains[4] = {
        bn::sprite_items::mountains.create_sprite(-32 - 64, -16, 0),
        bn::sprite_items::mountains.create_sprite(-32, -16, 1),
        bn::sprite_items::mountains.create_sprite(32, -16, 2),
        bn::sprite_items::mountains.create_sprite(32 + 64, -16, 3)};

    bn::sprite_ptr trees01[4] = {
        bn::sprite_items::trees01.create_sprite(-32 - 64, 16, 0),
        bn::sprite_items::trees01.create_sprite(-32, 16, 1),
        bn::sprite_items::trees01.create_sprite(32, 16, 2),
        bn::sprite_items::trees01.create_sprite(32 + 64, 16, 3)};

    bn::sprite_ptr grass[2] = {
        bn::sprite_items::grass.create_sprite(88, 48, 1),
        bn::sprite_items::grass.create_sprite(24, 48, 0)};

    clouds[0].set_blending_enabled(true);
    clouds[1].set_blending_enabled(true);
    clouds[2].set_blending_enabled(true);
    clouds[3].set_blending_enabled(true);
    clouds[4].set_blending_enabled(true);
    clouds[5].set_blending_enabled(true);
    clouds[4].put_above();
    clouds[5].put_above();
    clouds[4].set_scale(0.5);
    clouds[5].set_scale(0.5);

    bn::vector<bn::sprite_ptr, 24> sparkles;
    for (int i = 0; i < 24; i++)
    {
        auto sparkle = bn::sprite_items::sparkle.create_sprite((rnd.get_int() % 240) - 120, (rnd.get_int() % 120) - 40);
        bn::fixed scale = (rnd.get_int() % 10 / bn::fixed(10));
        if (scale < 0.1)
        {
            scale = 0.1;
        }
        else if (scale > 1)
        {
            scale = 1;
        }
        sparkle.set_scale(scale, scale);
        sparkles.push_back(sparkle);
    }

    bn::blending::set_transparency_alpha(0.5);

    while (true)
    {
        ticker++;

        clouds[0].set_y((bn::degrees_sin(ticker) * 4) - 48);
        clouds[1].set_y((bn::degrees_sin(ticker) * 4) - 48);
        clouds[2].set_y((bn::degrees_sin(ticker + 16) * 4) - 36);
        clouds[3].set_y((bn::degrees_sin(ticker + 16) * 4) - 36);

        for (int i = 0; i < sparkles.size(); i++) {
            sparkles.at(i).set_y(sparkles.at(i).y() + (bn::degrees_sin(ticker + (i * 16)) / 48));
        }

        bn::core::update();
    }
}
