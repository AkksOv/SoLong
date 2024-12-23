# Nom de la bibliothèque (au lieu de l'exécutable)
NAME = game.a

# Liste des fichiers sources
SRCS = init_data.c map_rendering.c game_controls.c enemy.c counter.c clean_files.c

# Compiler et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fichiers objets générés à partir des sources
OBJS = $(SRCS:.c=.o)

# Règle principale (création de la bibliothèque)
all: $(NAME)

# Création de la bibliothèque statique
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "Bibliothèque statique créée avec succès !"

# Compilation des fichiers objets
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@rm -f $(OBJS)
	@echo "Fichiers objets supprimés."

# Nettoyage complet (objets + bibliothèque)
fclean: clean
	@rm -f $(NAME)
	@echo "Bibliothèque supprimée."

# Recompilation complète
re: fclean all

# Règles d'usage
.PHONY: all clean fclean re