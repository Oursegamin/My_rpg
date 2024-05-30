/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** pause_menu_setup
*/

#include "my.h"

static int setup_pause_sign(pause_t **pause, sfRenderWindow *window,
    sfVector2f *pos)
{
    (*pause)->font = sfFont_createFromFile(TITLE_FONT);
    (*pause)->textures[0] =
        sfTexture_createFromFile(PAUSE_BUTTON_PATH, NULL);
    (*pause)->textures[1] =
        sfTexture_createFromFile(PAUSE_SIGN_PATH, NULL);
    (*pause)->sprites[3] = sfSprite_create();
    sfSprite_setTexture((*pause)->sprites[3], (*pause)->textures[1],
        sfTrue);
    sfSprite_setOrigin((*pause)->sprites[3], (sfVector2f){32, 16});
    sfSprite_setPosition((*pause)->sprites[3], get_resize(window,
        (*pos).x, (*pos).y));
    sfSprite_setScale((*pause)->sprites[3], get_resize(window, 8, 7.5));
    (*pause)->text[3] = create_text((*pause)->font, "PAUSE",
        get_less_size(window, 96.0), get_resize(window,
            (*pos).x, (*pos).y));
    set_text_mid_origin((*pause)->text[3]);
    (*pos).y += 280;
    return OK;
}

static void setup_pause_buttons(pause_t **pause, sfRenderWindow *window,
    sfVector2f pos, int i)
{
    (*pause)->buttons_status[i] = NORMAL;
    (*pause)->sprites[i] = sfSprite_create();
    sfSprite_setTexture((*pause)->sprites[i], (*pause)->textures[0],
        sfTrue);
    set_sprite_button_mid_origin((*pause)->sprites[i]);
    sfSprite_setTextureRect((*pause)->sprites[i], PAUSE_BUTTON_RECT);
    sfSprite_setPosition((*pause)->sprites[i],
        get_resize(window, pos.x, pos.y));
    sfSprite_setScale((*pause)->sprites[i], get_resize(window, 11.28, 8.5));
}

static int setup_pause_sprites(pause_t **pause, sfRenderWindow *window)
{
    sfVector2f pos = get_resize(window, 960, 120);
    char *texts[3] = {"Reprendre", "Menu Principal", "Quitter"};

    (*pause)->font = sfFont_createFromFile(FONT);
    setup_pause_sign(pause, window, &pos);
    for (int i = 0; i < 3; i++) {
        setup_pause_buttons(pause, window, pos, i);
        if (!(*pause)->sprites || !(*pause)->sprites[i])
            return KO;
        (*pause)->text[i] = create_text((*pause)->font, texts[i],
            get_less_size(window, 72.0), get_resize(window,
                pos.x, pos.y - 15.0));
        set_text_mid_origin((*pause)->text[i]);
        pos.y += 240;
    }
    return OK;
}

int pause_menu_setup(game_t *game, sfRenderWindow *window)
{
    game->pause->background = sfRectangleShape_create();
    sfRectangleShape_setSize(game->pause->background,
        get_resize(window, 1920, 1080));
    sfRectangleShape_setFillColor(game->pause->background,
        sfColor_fromRGBA(50, 100, 50, 100));
    game->pause->textures = malloc(sizeof(sfTexture *) * 2);
    game->pause->sprites = malloc(sizeof(sfSprite *) * 4);
    game->pause->text = malloc(sizeof(sfText *) * 4);
    game->pause->buttons_status = malloc(sizeof(button_state_t *) * 3);
    if (!game->pause->textures || !game->pause->sprites || !game->pause->text)
        return KO;
    if (setup_pause_sprites(&(game->pause), window) == KO)
        return KO;
    return OK;
}
