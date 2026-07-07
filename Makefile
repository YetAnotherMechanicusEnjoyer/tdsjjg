CC	= clang++

SRC	=	$(wildcard src/*.cpp)

DIR_OBJ	=	.obj/

OBJ	=	$(SRC:%.cpp=$(DIR_OBJ)%.o)

CPPFLAGS	=	-std=c++20 -Iinclude -lsfml-graphics -lsfml-window -lsfml-system

DFLAGS	=	-g -Wall -Wextra -Werror

BINARY	=	tdsjjg

all: 	$(BINARY)

$(BINARY):	$(OBJ)
		@$(CC) $^ -o $@ $(CPPFLAGS)
		@echo -e "\x1b[36mMakefile -> compile\x1b[0m"

$(DIR_OBJ)%.o:	%.cpp
		@mkdir -p $(dir $@)
		@$(CC) $^ -c -o $@ $(CPPFLAGS)
		@echo -e "\x1b[36mMakefile -> $@\x1b[0m"

clean:
		@rm -rf $(DIR_OBJ)
		@rm -rf .ropeproject
		@rm -rf .cache
		@echo -e "\x1b[35mMakefile -> clean\x1b[0m"

fclean: clean
		@rm -f $(BINARY)
		@rm -f $(BINARY_TEST)
		@rm -f *.log
		@rm -f *.gcov
		@rm -f *.gcda
		@rm -f *.gcno
		@rm -rf .cache
		@rm -f vgcore.*
		@rm -rf $(DIR_OBJ)
		@echo -e "\x1b[35mMakefile -> fclean\x1b[34m"

re:		fclean all
		@rm -rf .ropeproject
		@rm -rf $(DIR_OBJ)
		@echo -e "\x1b[31mMakefile -> re\x1b[0m"


.PHONY: all clean fclean re
