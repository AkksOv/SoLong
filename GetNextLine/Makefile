# Nom de la bibliothèque (au lieu de l'exécutable)
NAME = get_next_line.a

# Liste des fichiers sources
SRCS = get_next_line.c get_next_line_utils.c

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