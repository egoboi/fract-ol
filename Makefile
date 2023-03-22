# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbrisson <fbrisson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 12:42:06 by fbrisson          #+#    #+#              #
#    Updated: 2023/03/22 14:15:33 by fbrisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

NAME = fractol

SOURCES = sources/main.c              		\
	  sources/colors_handler.c		\
	  sources/basic_forms.c			\
	  sources/events_handler.c		\
	  sources/mandelbrot.c		\

OBJECTS = ${SOURCES:.c=.o}

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror -g3

LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

HEADERS = -I includes/

INCLUDE = ./includes/fractol.h

CLEANER = rm -f

.c.o:
	@printf "\033[0;3%dmOBJECT [\033[0m" "$(COLOR_LIGHT_BLUE)"
	@printf "\033[0;3%dm%d\033[0m" "$(COLOR_YELLOW)" "$(nb)"
	@printf "\033[0;3%dm] -ready\033[0m\n" "$(COLOR_LIGHT_BLUE)"
	@printf "\033[0;3%dmCompiling... \033[0m" "$(COLOR_BLUE)"
	@if ( ${COMPILER} ${HEADERS} -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o} );\
	then; printf "\033[0;3%dmSUCCESS\033[0m\n" "$(COLOR_GREEN)";\
	else; printf "\033[0;3%dmFAILURE\033[0m\n" "$(COLOR_RED)";\
	fi
	$(eval nb=$(shell echo $$(($(nb)+1))))


${NAME}: ${OBJECTS}
	@${COMPILER} ${OBJECTS} ${HEADERS} ${LFLAGS} -o ${NAME}
	@printf "\033[0;39m   (づ ￣ ³￣)づ   "
	@printf "\033[0;34mC "
	@printf "\033[0;36mO "
	@printf "\033[0;34mM "
	@printf "\033[0;36mP "
	@printf "\033[0;34mI "
	@printf "\033[0;36mL "
	@printf "\033[0;34mA "
	@printf "\033[0;36mT "
	@printf "\033[0;34mI "
	@printf "\033[0;36mO "
	@printf "\033[0;34mN "
	@printf "\033[0;36m   "
	@printf "\033[0;32mS "
	@printf "\033[0;32mU "
	@printf "\033[0;32mC "
	@printf "\033[0;32mC "
	@printf "\033[0;32mE "
	@printf "\033[0;32mS "
	@printf "\033[0;32mS "
	@printf "\033[0;32mF "
	@printf "\033[0;32mU "
	@printf "\033[0;32mL "
	@printf "\033[0;32mL "
	@printf "\033[0;39m    ~\(≧▽≦)/~ \033[0m\n"

nb:=1

COLOR_BLUE:=4

COLOR_LIGHT_BLUE:=6

COLOR_YELLOW:=3

COLOR_GREEN:=2

COLOR_RED:=1

all: ${NAME}

clean:
	@printf "\033[0;39m   (っ^з^)♪♬  \033[0m\n"
	@printf "\033[0;3%dmCleaning... \033[0m" "$(COLOR_BLUE)"
	@if ( ${CLEANER} ${OBJECTS} );\
	then; printf "\033[0;3%dmSUCCESS\033[0m\n" "$(COLOR_GREEN)";\
	else; printf "\033[0;3%dmFAILURE\033[0m\n" "$(COLOR_RED)";\
	fi

fclean: clean
	@printf "\033[0;39m   (ﾉ☉ヮ⚆)ﾉ   \033[0m\n"
	@printf "\033[0;3%dmFull Clean... \033[0m" "$(COLOR_BLUE)"
	@if ( ${CLEANER} ${NAME} );\
	then; printf "\033[0;3%dmSUCCESS\033[0m\n" "$(COLOR_GREEN)";\
	else; printf "\033[0;3%dmFAILURE\033[0m\n" "$(COLOR_RED)";\
	fi

re : fclean all

.PHONY: all clean fclean bonus re
