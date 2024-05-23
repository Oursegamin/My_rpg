/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** buy_article
*/

#include "my.h"

static void quitt_buy_item(rpg_t *rpg, sfSprite *sprite, sfVector2f mouse_pos)
{
    if (get_sprite_bounds(sprite, mouse_pos) == sfTrue) {
        rpg->game->interaction->shop = QUITT;
    }
}

static void buy_potion(rpg_t *rpg, sfRectangleShape *shape,
    sfVector2f mouse_pos)
{
    if (get_rectangle_bounds(shape, mouse_pos) == sfTrue) {
        return;
    }
}

static void buy_weapon(rpg_t *rpg, sfRectangleShape *shape,
    sfVector2f mouse_pos)
{
    if (get_rectangle_bounds(shape, mouse_pos) == sfTrue) {
        return;
    }
}

static void check_shop(rpg_t *rpg, sfEvent event)
{
    sfVector2i mouse_pos_int = {event.mouseButton.x, event.mouseButton.y};
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window,
        mouse_pos_int, rpg->game->map->view);

    if (rpg->game->map->choice_map == FORGE) {
        for (int i = 0; i < 3; i++) {
            buy_weapon(rpg, rpg->game->shop->
            weapon[rpg->game->player->race]->zone_text[i], mouse_pos);
        }
        quitt_buy_item(rpg, rpg->game->shop->sprite_quitt[0], mouse_pos);
    }
    if (rpg->game->map->choice_map == ALCHEMY) {
        for (int i = 0; i < 2; i++) {
            buy_potion(rpg, rpg->game->shop->potion->zone_text[i],
            mouse_pos);
        }
        quitt_buy_item(rpg, rpg->game->shop->sprite_quitt[1], mouse_pos);
    }
}

int buy_article(rpg_t *rpg, sfEvent event)
{
    if (event.mouseButton.type == sfEvtMouseButtonReleased) {
        check_shop(rpg, event);
    }
    return OK;
}
