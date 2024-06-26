/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** interaction_event
*/

#include "my.h"

static void actions_rect_reponse(rpg_t *rpg, sfRectangleShape **shape,
    sfVector2f mouse_pos)
{
    if (rpg->game->map->choice_map == ALCHEMY)
        rpg->game->player->position = (sfVector2f){140.0, 415.0};
    if (rpg->game->map->choice_map == FORGE)
        rpg->game->player->position = (sfVector2f){816.0, 610.0};
    if (get_rectangle_bounds(shape[0], mouse_pos) == sfTrue)
        rpg->game->interaction->shop = BUY;
    if (get_rectangle_bounds(shape[1], mouse_pos) == sfTrue) {
        rpg->game->interaction->shop = QUITT;
        sfSprite_setPosition(rpg->game->player->sprites->player,
            rpg->game->player->position);
        sfSprite_setScale(rpg->game->player->sprites->player,
            (sfVector2f){0.5, 0.5});
        rpg->game->map->choice_map = VILLAGE;
        sfMusic_stop(rpg->game->map->house[0]->house_music);
        sfMusic_play(rpg->game->map->game_sound);
    }
}

void interaction_event(rpg_t *rpg, sfEvent event)
{
    sfVector2i mouse_pos_int = {event.mouseButton.x, event.mouseButton.y};
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window,
        mouse_pos_int, rpg->game->map->view);

    if (event.mouseButton.type == sfEvtMouseButtonReleased) {
        for (int i = 0; i < 2; i++) {
            actions_rect_reponse
                (rpg, rpg->game->interaction->zone_text[i], mouse_pos);
        }
    }
}
