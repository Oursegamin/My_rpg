/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #include "rpg.h"

char *check_env(char const *const *env);
char *fs_open_file(char const *filepath);
int error_handling(int argc, char const *const *argv);

int launch_rpg(char const *user);
int rpg_loop(rpg_t *rpg);
// void event_manager(rpg_t *rpg);
void destroy_resources(rpg_t *rpg);

/* FCT Générique*/
sfSprite *create_button(sfTexture *texture, sfVector2f scale, sfVector2f pos);

/* MENU */
int setup_menu(rpg_t *rpg);
int setup_background_menu(menu_t *menu);
void background_menu_manager(menu_t *menu);

#endif /* PROTO_H_ */
