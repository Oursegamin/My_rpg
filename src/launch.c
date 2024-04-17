/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Launch
*/

#include "my.h"

static int rpg_setup(rpg_t *rpg, char const *user)
{
    if (setup_menu(rpg) == KO)
        return KO;
    return OK;
}

int launch_rpg(char const *user)
{
    rpg_t rpg = {};
    sfVideoMode videoMode = {1920, 1080, 60};

    rpg.window = sfRenderWindow_create(videoMode,
    "World_of_Sylveria", sfClose | sfResize, NULL);
    if (rpg_setup(&rpg, user) == KO)
        return KO;
    return rpg_loop(&rpg);
}