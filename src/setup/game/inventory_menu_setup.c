/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** pause_menu_setup
*/

#include "my.h"

static int setup_inventory_bg_loop(inventory_t **inventory,
    sfVector2f *inventory_pos, sfVector2f *inventory_scale, int i)
{
    (*inventory)->sprites[i] = sfSprite_create();
    sfSprite_setTexture((*inventory)->sprites[i],
        (*inventory)->textures[i], sfFalse);
    set_sprite_mid_origin((*inventory)->sprites[i]);
    sfSprite_setPosition((*inventory)->sprites[i],
        inventory_pos[i]);
    sfSprite_setScale((*inventory)->sprites[i], inventory_scale[i]);
    if (!(*inventory)->sprites || !(*inventory)->sprites[i])
        return KO;
    return OK;
}

static int setup_inventory_bg_texts(inventory_t **inventory,
    sfRenderWindow *window, sfFont *font, sfVector2f pos)
{
    char *texts[6] = {"INVENTORY", "POINT DE VIE", "MANA", "DEFENSE",
        "ATTAQUE PHYSIQUE", "ATTAQUE MAGIQUE"};

    (*inventory)->text[0] = create_text(font, texts[0],
        get_less_size(window, 72.0), (sfVector2f){pos.x,
        pos.y - 20});
        set_text_mid_origin((*inventory)->text[0]);
    pos = (sfVector2f){1290, 371};
    for (int i = 1; i < 6; i++) {
    (*inventory)->text[i] = create_text(font, texts[i],
        get_less_size(window, 25.0), (sfVector2f){pos.x,
        pos.y});
        pos.y += 134.5;
    }
    return OK;
}

static int setup_inventory_background(inventory_t **inventory,
    sfRenderWindow *window, sfFont *font)
{
    char const *path[3] = {INVENTORY_SIGN_PATH, INVENTORY_SLOTS_PATH,
        INVENTORY_STATS_PATH};
    sfVector2f inventory_pos[3] = {get_resize(window, 960, 120),
        get_resize(window, 480, 650), get_resize(window, 1440, 650)};
    sfVector2f inventory_scale[3] = {get_resize(window, 8, 8),
        get_resize(window, 7.5, 7.5), get_resize(window, 8, 8)};

    if (setup_inventory_bg_texts(inventory, window, font,
        inventory_pos[0]) == KO)
        return KO;
    for (int i = 0; i < 3; i++) {
        (*inventory)->textures[i] = sfTexture_createFromFile(path[i], NULL);
        if (setup_inventory_bg_loop(inventory, inventory_pos,
            inventory_scale, i) == KO)
            return KO;
        (*inventory)->textures[i] = sfTexture_createFromFile(path[i], NULL);
    }
    return OK;
}

int inventory_menu_setup(game_t *game, sfRenderWindow *window)
{
    game->inventory->background = sfRectangleShape_create();
    sfRectangleShape_setSize(game->inventory->background,
        get_resize(window, 1920, 1080));
    sfRectangleShape_setFillColor(game->inventory->background,
        sfRectangleShape_getFillColor(game->pause->background));
    game->inventory->textures = malloc(sizeof(sfTexture *) * 4);
    game->inventory->sprites = malloc(sizeof(sfSprite *) * 4);
    game->inventory->text = malloc(sizeof(sfSprite *) * 7);
    if (!game->inventory->textures || !game->inventory->sprites)
        return KO;
    game->inventory->sprites[3] = NULL;
    game->inventory->textures[3] = NULL;
    game->inventory->textures[6] = NULL;
    if (setup_inventory_background(&game->inventory,
        window, game->pause->font) == KO)
        return KO;
    return OK;
}
