# Nom de l'exécutable
NAME = get_next_line

# Liste des fichiers sources
SRCS = get_next_line.c get_next_line_utils.c

# Compiler et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fichiers objets générés à partir des sources
OBJS = $(SRCS:.c=.o)

# Règle principale
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation réussie !"

# Compilation des fichiers objets
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@rm -f $(OBJS)
	@echo "Fichiers objets supprimés."

# Nettoyage complet (objets + exécutable)
fclean: clean
	@rm -f $(NAME)
	@echo "Exécutable supprimé."

# Recompilation complète
re: fclean all

# Règles d'usage
.PHONY: all clean fclean re