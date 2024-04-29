/*
** EPITECH PROJECT, 2024
** B-MUL-200-BDX-2-1-myrpg-armand.dufresne
** File description:
** settings
*/

#ifndef SETTINGS_H_
    #define SETTINGS_H_

    #define OPEN_BOOK_P "assets/book_animation/book_1.png"
    #define NEXT_PAGE_P "assets/book_animation/book_2.png"
    #define PREVIOUS_PAGE_P "assets/book_animation/book_3.png"
    #define CLOSE_BOOK_P "assets/book_animation/book_4.png"

typedef struct rect_s {
    sfIntRect rect;
    sfIntRect ract;
    sfIntRect ruct;
    sfIntRect rict;
} rect_t;

typedef struct anim_s {
    sfTexture *open_book;
    sfSprite *open_book_spr;
    sfTexture *next_page;
    sfSprite *next_page_spr;
    sfTexture *previous_page;
    sfSprite *previous_page_spr;
    sfTexture *close_book;
    sfSprite *close_book_spr;
    sfClock *book_clock;
} anim_t;

typedef struct settings_s {
    rect_t *react;
    anim_t *anim;
} settings_t;

#endif /* !SETTINGS_H_ */