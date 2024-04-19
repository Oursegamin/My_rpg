/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include "main_menu.h"
    #include "help.h"
    #include "settings.h"

    #include <SFML/Audio.h>

    #define BACKGROUND "assets/sprite/background_menu.png"
    #define WOS_SIGN "assets/sprite/tropical_button.png"
    #define PLAYER "assets/sprite/main_character.png"
    #define BUTTON_OPTION "assets/button/option.png"
    #define BUTTON_PANEL "assets/button/wood_button.png"
    #define BUTTON_MENU "assets/button/button.png"
    #define FONT "assets/Font/game_over.ttf"
    #define TITLE_FONT "assets/Font/GAMERIA.ttf"
    #define MUSIC_MENU "assets/music/menu_music.ogg"
    #define BG_RECT ((sfIntRect) {0, 0, 560, 272})
    #define BUTTON_RECT ((sfIntRect) {0.0, 0.0, 748.0, 287.0})
    #define HUMAN_RECT ((sfIntRect) {210, 0, 52, 56})
    #define DWARF_RECT ((sfIntRect) {156, 110, 52, 60})
    #define ELF_RECT ((sfIntRect) {212, 228, 52, 62})

typedef enum menu_state_s {
    MAIN,
    HELP,
    SETTING,
    MAIN_MENU_STATE_SIZE
} menu_state_t;

typedef struct background_menu_s {
    sfClock *bg_anim_clock;

    sfSprite *background_sprite;
    sfTexture *background_texture;

    sfTexture *characters_texture;
    sfSprite **characters;
} background_menu_t;

typedef struct menu_s {
    menu_state_t screen;

    sfMusic *menu_sound;

    background_menu_t *background;

    main_menu_t *main_menu;
    help_t *help;
    settings_t *settings;
} menu_t;

#endif /* !MENU_H_ */
