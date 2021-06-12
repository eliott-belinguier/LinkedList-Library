#################
# SOURCES FILES #
#################
DIR_SRC = src
DIR_INCLUDE = include

DIR_TEST_TOOLS = tests/src
DIR_TEST = tests/list/src
DIR_TEST_INCLUDE = tests/include

DIR_BONUS = bonus

SRC += src/add.c
SRC += src/count.c
SRC += src/get.c
SRC += src/next.c
SRC += src/node_next.c
SRC += src/node_prev.c
SRC += src/remove.c
SRC += src/rotate_next.c
SRC += src/rotate_prev.c

SRC_TEST += $(DIR_TEST_TOOLS)/malloc.c
SRC_TEST += $(DIR_TEST)/add.c
SRC_TEST += $(DIR_TEST)/count.c
SRC_TEST += $(DIR_TEST)/get.c
SRC_TEST += $(DIR_TEST)/next.c
SRC_TEST += $(DIR_TEST)/node_next.c
SRC_TEST += $(DIR_TEST)/node_prev.c
SRC_TEST += $(DIR_TEST)/remove.c
SRC_TEST += $(DIR_TEST)/rotate_next.c
SRC_TEST += $(DIR_TEST)/rotate_prev.c

#SRC_BONUS += $(DIR_SRC)/opt_display.c

#############
# VARIABLES #
#############
OBJ = $(SRC:.c=.o) $(SRC_MAIN:.c=.o)

OBJ_BONUS = $(OBJ) $(SRC_BONUS:.c=.o)

OBJ_TEST = $(SRC:.c=.o) $(SRC_TEST:.c=.o)

CPPFLAGS = -iquote $(DIR_INCLUDE)

CFLAGS = -Wall -Wextra

NAME = liblinkedlist.a

NAME_TEST = unit_tests

ifdef DEBUG
	CFLAGS += -DDEBUG=1 -ggdb3
endif

###########
# RECIPES #
###########
ifdef DEBUG

%.o: %.c
	@ gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $< && echo -n "\033[92m[ OK ]\033[0m" || echo -n "\033[91m[ ERROR ]\033[0m"
	@ echo "" $<

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ) && echo -n "\033[92m[ OK ]\033[0m" || echo -n "\033[91m[ ERROR ]\033[0m"
	@ echo "" $(NAME)

.PHONY: bonus
bonus: fclean $(OBJ_BONUS)
	@ gcc -o $(NAME) $(OBJ_BONUS) $(LDFLAGS) && echo -n "\033[92m[ OK ]\033[0m" || echo -n "\033[91m[ ERROR ]\033[0m"
	@ echo "" $(NAME)

.PHONY: clean
clean:
	@ for file in $(OBJ_SRC); do \
		rm -f $$file && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"; \
		echo "" $$file; \
	done
	@ for file in $(OBJ_TEST); do \
		rm -f $$file && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"; \
		echo "" $$file; \
	done
	@ for file in $(OBJ_BONUS); do \
		rm -f $$file && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"; \
		echo "" $$file; \
	done
	@ for file in $(shell find -type f -name "*.gc[nd][oa]" ); do \
		rm -f $$file && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"; \
		echo "" $$file; \
	done

.PHONY: fclean
fclean: clean
	@ rm -f $(NAME) && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"
	@ echo "" $(NAME)
	@ rm -f $(NAME_TEST) && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"
	@ echo "" $(NAME_TEST)
	@ rm -rf coverage && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"
	@ echo "" "coverage"
	@ find -type f \( -name "*.gcda" -o -name "*gcno" \) -exec rm {} \; && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"
	@ echo "" "tests files"

.PHONY: tests_run
tests_run: LDFLAGS += -lcriterion -lgcov
tests_run: CPPFLAGS += -iquote $(DIR_TEST_INCLUDE) --coverage
tests_run: fclean $(OBJ_TEST)
	@ gcc -o $(NAME_TEST) $(OBJ_TEST) $(LDFLAGS) && echo -n "\033[92m[ OK ]\033[0m" || echo -n "\033[91m[ ERROR ]\033[0m"
	@ echo "" $(NAME_TEST)
	@ [ -f ./$(NAME_TEST) ] && ./$(NAME_TEST)

else

%.o: %.c
	@ gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $< 1> /dev/null 2> /dev/null && echo -n "\033[92m[ OK ]\033[0m" || echo -n "\033[91m[ ERROR ]\033[0m"
	@ echo "" $<

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ) 1> /dev/null 2> /dev/null && echo -n "\033[92m[ OK ]\033[0m" || echo -n "\033[91m[ ERROR ]\033[0m"
	@ echo "" $(NAME)

.PHONY: bonus
bonus: fclean $(OBJ_BONUS)
	@ gcc -o $(NAME) $(OBJ_BONUS) $(LDFLAGS) 1> /dev/null 2> /dev/null && echo -n "\033[92m[ OK ]\033[0m" || echo -n "\033[91m[ ERROR ]\033[0m"
	@ echo "" $(NAME)

.PHONY: clean
clean:
	@ for file in $(OBJ_SRC); do \
		rm -f $$file 1> /dev/null 2> /dev/null && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"; \
		echo "" $$file; \
	done
	@ for file in $(OBJ_TEST); do \
		rm -f $$file 1> /dev/null 2> /dev/null && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"; \
		echo "" $$file; \
	done
	@ for file in $(OBJ_BONUS); do \
		rm -f $$file 1> /dev/null 2> /dev/null && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"; \
		echo "" $$file; \
	done
	@ for file in $(shell find -type f -name "*.gc[nd][oa]" ); do \
		rm -f $$file 1> /dev/null 2> /dev/null && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"; \
		echo "" $$file; \
	done

.PHONY: fclean
fclean: clean
	@ rm -f $(NAME) 1> /dev/null 2> /dev/null && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"
	@ echo "" $(NAME)
	@ rm -f $(NAME_TEST) 1> /dev/null 2> /dev/null && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"
	@ echo "" $(NAME_TEST)
	@ rm -rf coverage 1> /dev/null 2> /dev/null && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"
	@ echo "" "coverage"
	@ find -type f \( -name "*.gcda" -o -name "*gcno" \) -exec rm {} \; && echo -n "\033[92m[ REMOVE ]\033[0m" || echo -n "\033[91m[ REMOVE ]\033[0m"
	@ echo "" "tests files"

.PHONY: tests_run
tests_run: LDFLAGS += -lcriterion -lgcov
tests_run: CPPFLAGS += -iquote $(DIR_TEST_INCLUDE) --coverage
tests_run: fclean $(OBJ_TEST)
	@ gcc -o $(NAME_TEST) $(OBJ_TEST) $(LDFLAGS) 1> /dev/null 2> /dev/null && echo -n "\033[92m[ OK ]\033[0m" || echo -n "\033[91m[ ERROR ]\033[0m"
	@ echo "" $(NAME_TEST)
	@ [ -f ./$(NAME_TEST) ] && ./$(NAME_TEST)

endif

.PHONY: all
all: $(NAME)

.PHONY: re
re: fclean all

.PHONY: coverage
coverage: fclean tests_run
	@ gcovr --branches --exclude tests
	@ mkdir coverage && gcovr --branches --exclude tests --html-details -o ./coverage/index.html  && echo -n "\033[92m[ CREATE ]\033[0m" || echo -n "\033[91m[ CREATE ]\033[0m"
	@ echo "" "coverage"
