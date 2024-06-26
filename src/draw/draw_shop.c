/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_forge
*/

#include "my.h"

static void draw_rectangle(sfRenderWindow *window, sfRectangleShape **shape)
{
    for (int i = 0; i < 2; i += 1) {
        sfRenderWindow_drawRectangleShape(window, shape[i], NULL);
    }
}

static void draw_bubble_forgeron(sfRenderWindow *window, game_t *game)
{
    for (int i = 0; i < 2; i++) {
        if (game->interaction->field[i] == game->map->choice_map) {
            sfRenderWindow_drawSprite(window, game->interaction->sprite[i],
                NULL);
            draw_rectangle(window, game->interaction->zone_text[i]);
            sfRenderWindow_drawText(window, game->interaction->text[i], NULL);
        }
    }
}

static void draw_bubble_alchemist(sfRenderWindow *window, game_t *game)
{
    for (int i = 0; i < 2; i++) {
        if (game->interaction->field[i] == game->map->choice_map) {
            sfRenderWindow_drawSprite(window, game->interaction->sprite[i],
                NULL);
            draw_rectangle(window, game->interaction->zone_text[i]);
            sfRenderWindow_drawText(window, game->interaction->text[i], NULL);
        }
    }
}

static void draw_alchemist_text(sfRenderWindow *window, game_t *game)
{
    for (int i = 0; i < 2; i += 1) {
        sfRenderWindow_drawRectangleShape(window,
            game->shop->potion->zone_text[i], NULL);
        sfRenderWindow_drawText(window, game->shop->potion->text[i], NULL);
        if (game->player->stats.nb_gold < 50) {
            sfText_setColor(game->shop->potion->text[i], sfRed);
        } else
            sfText_setColor(game->shop->potion->text[i], sfBlack);
    }
}

void draw_alchemist(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->map->house[1]->house, NULL);
    sfRenderWindow_drawSprite(window, game->player->sprites->player, NULL);
    if (game->interaction->shop == QUITT)
        draw_bubble_alchemist(window, game);
    if (game->interaction->shop == BUY) {
        sfRenderWindow_drawSprite(window, game->shop->sprite_sign[1], NULL);
        sfRenderWindow_drawSprite(window, game->shop->sprite_quitt[1], NULL);
        sfRenderWindow_drawSprite(window, game->shop->potion->sprite, NULL);
        draw_alchemist_text(window, game);
    }
}

static void draw_forge_text(sfRenderWindow *window, game_t *game)
{
    int gold[3] = {50, 200, 500};

    for (int i = 0; i < 3; i += 1) {
        sfRenderWindow_drawRectangleShape(window,
            game->shop->weapon[game->player->race]->zone_text[i], NULL);
        sfRenderWindow_drawText(window,
            game->shop->weapon[game->player->race]->text[i], NULL);
        if (game->player->stats.nb_gold < gold[i]) {
            sfText_setColor(game->shop->weapon[game->player->race]->text[i],
            sfRed);
        } else
            sfText_setColor(game->shop->weapon[game->player->race]->text[i],
            sfBlack);
    }
}

void draw_forge(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->map->house[0]->house, NULL);
    sfRenderWindow_drawSprite(window, game->player->sprites->player, NULL);
    if (game->interaction->shop == QUITT)
        draw_bubble_forgeron(window, game);
    if (game->interaction->shop == BUY) {
        sfRenderWindow_drawSprite(window, game->shop->sprite_sign[0], NULL);
        sfRenderWindow_drawSprite(window, game->shop->sprite_quitt[0], NULL);
        sfRenderWindow_drawSprite(window,
            game->shop->weapon[game->player->race]->sprite_weap, NULL);
        draw_forge_text(window, game);
    }
}
