/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** draw_menu
*/

#include "my.h"

static void draw_help_menu(sfRenderWindow *window, menu_t *menu)
{
    setup_help_menu(window, menu);
    sfRenderWindow_drawText(window, menu->help_menu->text, NULL);
    sfRenderWindow_drawText(window, menu->help_menu->text, NULL);
    sfText_setPosition(menu->help_menu->text, (sfVector2f){1300, 450});
    sfText_setString(menu->help_menu->text, "Touches\n\n   Z\nQSD");
    sfRenderWindow_drawText(window, menu->help_menu->text, NULL);
    sfText_setPosition(menu->help_menu->text, (sfVector2f){500, 450});
    sfText_setString(menu->help_menu->text,
    "Createurs\n\nFlorian\nFaris\nBaptiste\nAxel\nArmand");
    sfRenderWindow_drawText(window, menu->help_menu->text, NULL);
}

static void draw_option_menu(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->settings->book_sp[0], NULL);
    open_close_book(menu->settings->book_sp[0], menu->settings->b_clock);
    sfRenderWindow_drawSprite(window, menu->settings->extern_sp[0], NULL);
    sfRenderWindow_drawSprite(window, menu->settings->extern_sp[1], NULL);
    sfRenderWindow_drawSprite(window, menu->settings->extern_sp[2], NULL);
    if (sfSprite_getTextureRect(menu->settings->book_sp[0]).left >= 2709) {
        if (menu->settings->current_page == 0)
            display_page_1(window, menu);
        if (menu->settings->current_page == 1)
            display_page_2(window, menu);
    }
    draw_arrows_and_turn_pages(window, menu);
}

static void draw_main_menu(sfRenderWindow *window, menu_t *menu)
{
    for (int i = 0; menu->main_menu->buttons->sprites[i] != NULL; i++) {
        sfRenderWindow_drawSprite(window,
            menu->main_menu->buttons->sprites[i], NULL);
        sfRenderWindow_drawText(window,
            menu->main_menu->buttons->text[i], NULL);
    }
    sfRenderWindow_drawSprite(window,
        menu->main_menu->buttons->help_back_spr, NULL);
    sfRenderWindow_drawSprite(window,
        menu->main_menu->buttons->help_book_spr, NULL);
}

static void draw_menu_background(sfRenderWindow *window,
    background_menu_t *background)
{
    sfRenderWindow_drawSprite(window, background->background_sprite, NULL);
    for (int i = 0; background->characters[i] != NULL; i++)
        sfRenderWindow_drawSprite(window, background->characters[i], NULL);
}

static void draw_parallax(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->parallax->background_sprite, NULL);
    for (int i = 0; i < NB_PARALLAX; i++) {
        sfRenderWindow_drawSprite(window, menu->parallax->sprites[i], NULL);
        sfSprite_move(menu->parallax->sprites[i], (sfVector2f){-1920, 0});
        sfRenderWindow_drawSprite(window, menu->parallax->sprites[i], NULL);
        sfSprite_move(menu->parallax->sprites[i], (sfVector2f){1920, 0});
    }
    sfRenderWindow_drawText(window, menu->parallax->parallax_text, NULL);
}

void draw_menu(rpg_t *rpg)
{
    void (*draw_menu_fct[])(sfRenderWindow *, menu_t *) =
        {draw_parallax, draw_main_menu, draw_help_menu, draw_option_menu,
        draw_help_menu};

    if (rpg->menu->screen != PARALLAX) {
        draw_menu_background(rpg->window, rpg->menu->background);
        sfRenderWindow_drawSprite(rpg->window,
        rpg->menu->main_menu->wos_sprite,
            NULL);
        sfRenderWindow_drawText(rpg->window, rpg->menu->main_menu->wos, NULL);
    }
    draw_menu_fct[rpg->menu->screen](rpg->window, rpg->menu);
}
