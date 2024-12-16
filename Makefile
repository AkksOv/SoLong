# Nom de l'exécutable final
NAME = Solong

# Répertoires contenant les bibliothèques et les sources
GNL_DIR = GetNextLine
UTILS_DIR = Utils
GAME_DIR = game
# Bibliothèques compilées
GNL_LIB = $(GNL_DIR)/get_next_line.a
UTILS_LIB = $(UTILS_DIR)/utils.a
GAME_LIB = $(GAME_DIR)/game.a
# Fichiers source et objets du programme principal
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Inclusion des headers
INCLUDES = -I $(GNL_DIR) -I $(UTILS_DIR)

# Compiler et options
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Règle principale pour construire l'exécutable
all: $(GNL_LIB) $(UTILS_LIB) $(NAME)

# Construction de l'exécutable final
$(NAME): $(OBJS) $(GNL_LIB) $(UTILS_LIB) $(GAME_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(GAME_DIR) $(GAME_LIB) -L$(UTILS_DIR) $(UTILS_LIB) -L$(GNL_DIR) $(GNL_LIB) -o $(NAME)
	@echo "Exécutable $(NAME) créé avec succès !"

# Compilation des fichiers objets du programme principal
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Construction des bibliothèques
$(GNL_LIB):
	@make -C $(GNL_DIR)

$(UTILS_LIB):
	@make -C $(UTILS_DIR)

# Nettoyage des fichiers objets et des bibliothèques
clean:
	rm -f $(OBJS)
	@make -C $(GNL_DIR) clean
	@make -C $(UTILS_DIR) clean
	@echo "Fichiers objets et fichiers temporaires supprimés."

# Nettoyage complet (objets + exécutable + bibliothèques)
fclean: clean
	rm -f $(NAME)
	@make -C $(GNL_DIR) fclean
	@make -C $(UTILS_DIR) fclean
	@echo "Exécutable et bibliothèques supprimés."

# Recompilation complète
re: fclean all

# Règles d'usage
.PHONY: all clean fclean re