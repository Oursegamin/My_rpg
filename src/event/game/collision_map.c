/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** collision_map
*/

#include "my.h"

static void enter_house(game_t *game, sfRenderWindow *window, sfVector2f pos,
    choice_map_t choice)
{
    reset_view(game->map->view, window, (sfVector2f){1920, 1080});
    game->player->position = pos;
    sfSprite_setPosition
        (game->player->sprites->player, game->player->position);
    if (choice == FORGE) {
        sfSprite_setScale(game->player->sprites->player, (sfVector2f){4, 5});
    } else
        sfSprite_setScale(game->player->sprites->player,
            (sfVector2f){2.75, 3});
    sfMusic_stop(game->map->game_sound);
    sfMusic_play(game->map->house[0]->house_music);
    game->player_move = (sfVector2f){0, 0};
    game->map->choice_map = choice;
}

static void check_top_and_down(game_t *game, sfVector2f *pos_1,
    sfVector2f *pos_2, sfVector2f *pos_3)
{
    if (game->player_move.y > 0) {
        (*pos_1).x += (game->player->sprites->player_rect.width / 4);
        (*pos_1).y += (game->player->sprites->player_rect.height / 4) + 1;
        (*pos_2).x -= (game->player->sprites->player_rect.width / 4);
        (*pos_2).y += (game->player->sprites->player_rect.height / 4) + 1;
        (*pos_3).y += (game->player->sprites->player_rect.height / 4) + 1;
    }
    if (game->player_move.y < 0) {
        (*pos_1).x += (game->player->sprites->player_rect.width / 4);
        (*pos_1).y -= (game->player->sprites->player_rect.height / 4) + 1;
        (*pos_2).x -= (game->player->sprites->player_rect.width / 4);
        (*pos_2).y -= (game->player->sprites->player_rect.height / 4) + 1;
        (*pos_3).y -= (game->player->sprites->player_rect.height / 4) + 1;
    }
}

static int top_down(game_t *game, sfRenderWindow *window)
{
    sfColor color1 = sfBlack;
    sfColor color2 = sfBlack;
    sfColor color3 = sfBlack;
    sfVector2f pos_1 = game->player->position;
    sfVector2f pos_2 = game->player->position;
    sfVector2f pos_3 = game->player->position;

    check_top_and_down(game, &pos_1, &pos_2, &pos_3);
    color1 = sfImage_getPixel(game->map->layers, pos_1.x, pos_1.y);
    color2 = sfImage_getPixel(game->map->layers, pos_2.x, pos_2.y);
    color3 = sfImage_getPixel(game->map->layers, pos_3.x, pos_3.y);
    if (color1.a == 0 || color2.a == 0 || color3.a == 0)
        return KO;
    if (color1.g == 254 || color2.g == 254 || color3.g == 254)
        enter_house(game, window, (sfVector2f){880, 800}, FORGE);
    if (color1.r == 254 || color2.r == 254 || color3.r == 254)
        enter_house(game, window, (sfVector2f){875, 755}, ALCHEMY);
    return OK;
}

static void check_left_and_right(game_t *game, sfVector2f *pos_1,
    sfVector2f *pos_2, sfVector2f *pos_3)
{
    if (game->player_move.x > 0) {
        (*pos_1).x += (game->player->sprites->player_rect.width / 4) + 1;
        (*pos_1).y += (game->player->sprites->player_rect.height / 4);
        (*pos_2).x += (game->player->sprites->player_rect.width / 4) + 1;
        (*pos_2).y -= (game->player->sprites->player_rect.height / 4);
        (*pos_3).x += (game->player->sprites->player_rect.width / 4) + 1;
    }
    if (game->player_move.x < 0) {
        (*pos_1).x -= (game->player->sprites->player_rect.width / 4) + 1;
        (*pos_1).y += (game->player->sprites->player_rect.height / 4);
        (*pos_2).x -= (game->player->sprites->player_rect.width / 4) + 1;
        (*pos_2).y -= (game->player->sprites->player_rect.height / 4);
        (*pos_3).x -= (game->player->sprites->player_rect.width / 4) + 1;
    }
}

static int left_right(game_t *game)
{
    sfColor color1 = sfBlack;
    sfColor color2 = sfBlack;
    sfColor color3 = sfBlack;
    sfVector2f pos_1 = game->player->position;
    sfVector2f pos_2 = game->player->position;
    sfVector2f pos_3 = game->player->position;

    check_left_and_right(game, &pos_1, &pos_2, &pos_3);
    color1 = sfImage_getPixel(game->map->layers, pos_1.x, pos_1.y);
    color2 = sfImage_getPixel(game->map->layers, pos_2.x, pos_2.y);
    color3 = sfImage_getPixel(game->map->layers, pos_3.x, pos_3.y);
    if (color1.a == 0 || color2.a == 0 || color3.a == 0)
        return KO;
    return OK;
}

static void map_move(game_t *game)
{
    game->map->rect.left = game->player->position.x - 200;
    game->map->rect.top = game->player->position.y - 100;
    if (game->player->position.x > 200 && game->player->position.x < 760)
        game->map->rect.left += game->player_move.x;
    if (game->player->position.y > 100 && game->player->position.y < 595)
        game->map->rect.top += game->player_move.y;
}

static int sprite_move_player(game_t *game, sfRenderWindow *window)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
        (game->player->sprites->move_clock)) > 0.6) {
        if (game->player_move.x != 0 && left_right(game) == OK) {
            sfSprite_move(game->player->sprites->player,
            (sfVector2f){game->player_move.x, 0});
            game->player->position.x += game->player_move.x;
        }
        if (game->player_move.y != 0 && top_down(game, window) == OK) {
            sfSprite_move(game->player->sprites->player,
            (sfVector2f){0, game->player_move.y});
            game->player->position.y += game->player_move.y;
        }
        sfClock_restart(game->player->sprites->move_clock);
    }
    map_move(game);
    return OK;
}

void change_view(game_t *game, sfRenderWindow *window)
{
    if (sprite_move_player(game, window) == OK) {
        if (game->map->rect.top < 0)
            game->map->rect.top = 0;
        if (game->map->rect.top > 495)
            game->map->rect.top = 495;
        if (game->map->rect.left < 0)
            game->map->rect.left = 0;
        if (game->map->rect.left > 560)
            game->map->rect.left = 560;
        if (game->map->choice_map == VILLAGE) {
            game->map->view = sfView_createFromRect(game->map->rect);
            sfRenderWindow_setView(window, game->map->view);
        }
    }
}
