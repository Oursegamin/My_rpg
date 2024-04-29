/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #define MAP_P "assets/map/map_rpg.png"
    #define MAP_OBJ "assets/map/map_rpg_texture.png"
    #define AMB_MUSIC "assets/music/ambiance_music.ogg"

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

typedef struct map_s {
    sfTexture *texture_obj;
    sfSprite *sprite_obj;

    sfMusic *game_sound;

    sfTexture *texture_ground;
    sfSprite *sprite_ground;
    sfView *view;
    sfFloatRect rect;
} map_t;

#endif /* !MAP_H_ */
