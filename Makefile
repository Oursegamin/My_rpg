##
## EPITECH PROJECT, 2023
## Makefiles
## File description:
## solostumper
##

MAIN	=	main.c										\

SRC =		src/error_handling.c						\
			src/read_file.c								\
			src/check_env.c								\
			src/launch.c								\
			src/rpg_loop.c								\

GLOBALS	=	src/global_functions/create_button.c		\
			src/global_functions/create_text.c			\
			src/global_functions/hover_functions.c		\
			src/global_functions/bounds_functions.c		\
			src/global_functions/blanck_line.c			\
			src/global_functions/check_commentary.c		\
			src/global_functions/get_resize.c			\
			src/global_functions/set_mid_origin.c		\
			src/global_functions/set_volume_music.c		\
			src/global_functions/read_dialogue_file.c	\
			src/global_functions/reset_view.c			\

SETUP	=	src/setup/menu_setup.c						\
			src/setup/menu/background_menu_setup.c		\
			src/setup/menu/menu_button_setup.c			\
			src/setup/menu/option_menu_setup.c			\
			src/setup/menu/anim_book.c					\
			src/setup/menu/option_pages.c				\
			src/setup/game_setup.c						\
			src/setup/game/map_setup.c					\
			src/setup/game/player_setup.c				\
			src/setup/game/entities_setup.c				\
			src/setup/game/selection_charac.c			\
			src/setup/game/pause_menu_setup.c			\
			src/setup/game/inventory_menu_setup.c		\
			src/setup/game/particule_n_flag_set_up.c	\
			src/setup/menu/option_features.c 			\
			src/setup/menu/parallax_setup.c				\
			src/setup/game/interaction_setup.c			\
			src/setup/game/weapon_setup.c				\
			src/setup/game/item_inventory_setup.c	\
			src/setup/menu/setup_help.c 				\
			src/setup/game/villager_setup.c 			\

EVENT	=	src/event/event.c							\
			src/event/menu/main_menu_event.c			\
			src/event/menu/settings_menu_event.c		\
			src/event/game/select_event.c				\
			src/event/game/load_save_event.c			\
			src/event/game/game_event.c					\
			src/event/game/pause_menu_event.c			\
			src/event/game/inventory_menu_event.c		\
			src/event/game/collision_map.c				\
			src/event/game/battlefield_movement.c		\
			src/event/game/interaction_event.c			\
			src/event/game/buy_article.c				\
			src/event/menu/help_event.c					\
			src/event/game/battlefield_event.c			\

MANAGER	=	src/manager/menu_manager.c					\
			src/manager/background_menu_manager.c		\
			src/manager/game_manager.c					\
			src/manager/level_manager.c					\
			src/manager/ork_movement.c					\
			src/manager/ork_manager.c					\
			src/manager/call_function.c					\

DRAW	=	src/draw/draw_menu.c						\
			src/draw/draw_game.c						\
			src/draw/draw_shop.c						\
			src/draw/draw_particles_n_flag.c			\
			src/draw/draw_game_menus.c					\
			src/draw/draw_villagers.c 					\

SAVE	=	src/save/settings_game.c					\
			src/save/write_setting_in_file.c			\

DESTROY = 	src/destroy/destroy_rpg.c					\
			src/destroy/destroy_game.c					\
			src/destroy/destroy_menu.c					\

SRCTEST = 	tests/test_lib.c							\

OBJ = 	$(MAIN:.c=.o) $(SRC:.c=.o) $(SETUP:.c=.o) $(GLOBALS:.c=.o)\
		$(EVENT:.c=.o) $(MANAGER:.c=.o) $(SAVE:.c=.o) $(DRAW:.c=.o)\
		$(DESTROY:.c=.o)

OBJTEST = $(SRCTEST:.c=.o)

NAME =		my_rpg

NAMETEST = 	unit_tests

CFLAGS = -Wall -Wextra -g

CPPFLAGS	=	-I./include

LDFLAGS = -L./lib/my

LDLIBS 	=	-lmy -lm

GRAPHICS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

CC = gcc

all: buildlib $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS) $(GRAPHICS)

buildlib:
	make -C ./lib/my

buildlibtest: buildlib
	make -C ./lib/my CFLAGS='$(CFLAGS) --coverage'

buildtest: CFLAGS += --coverage
buildtest: buildlibtest $(OBJTEST)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $(NAMETEST) $(OBJTEST) $(SRC) $(LDLIBS)	\
	--coverage -lcriterion

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete
	find . -name "#*#" -delete
	find . -name "vgcore*" -delete
	find . -name "*.gcno" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcov" -delete
	find . -name "coding-style-reports.log" -delete
	find . -name "*.cor" -delete

fclean: clean cleantest
	rm -f $(NAME)
	make fclean -C ./lib/my

cleantest:
		rm -f $(NAMETEST)
		rm -f $(OBJTEST)

re: fclean all

valgrind: buildlib $(OBJ)
	$(CC) -g3 $(LDFLAGS) -o $(NAME) $(OBJ) $(LDLIBS)

unit_tests: buildtest

tests_run: unit_tests
		./unit_tests

.PHONY: all clean fclean re valgrind unit_tests tests_run cleantest
		buildlibtest buildtest buildlib
