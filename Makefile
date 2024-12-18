
# Nom de l'exécutable final
NAME = Solong

# Répertoires contenant les bibliothèques et les sources
GNL_DIR = GetNextLine
PRINTF_DIR = printf
UTILS_DIR = Utils
GAME_DIR = game
MLX_DIR = minilibx_linux
# Bibliothèques compilée
GNL_LIB = $(GNL_DIR)/get_next_line.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
UTILS_LIB = $(UTILS_DIR)/utils.a
GAME_LIB = $(GAME_DIR)/game.a
MLX_LIB = $(MLX_DIR)/libmlx.a
# Fichiers source et objets du programme principal
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Inclusion des headers
INCLUDES = -I $(GNL_DIR) -I $(PRINTF_DIR) -I $(UTILS_DIR) -I $(GAME_DIR) -I $(MLX_DIR)  

# Compiler et options
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# Règle principale pour construire l'exécutable
all: $(GNL_LIB) $(UTILS_LIB) $(NAME)

# Construction de l'exécutable final
$(NAME): $(OBJS) $(GNL_LIB) $(PRINTF_LIB) $(UTILS_LIB) $(GAME_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(GAME_DIR) $(GAME_LIB) -L$(UTILS_DIR) $(UTILS_LIB) -L$(PRINTF_DIR) $(PRINTF_LIB)  -L$(GNL_DIR) $(GNL_LIB) -o $(NAME) $(MLX_FLAGS)
	@echo "Exécutable $(NAME) créé avec succès !"

# Compilation des fichiers objets du programme principal
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Construction des bibliothèques
$(GNL_LIB):
	@make -C $(GNL_DIR)

$(UTILS_LIB):
	@make -C $(UTILS_DIR)

$(GAME_LIB):
	@make -C $(GAME_DIR)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)
# Nettoyage des fichiers objets et des bibliothèques
clean:
	rm -f $(OBJS)
	@make -C $(GNL_DIR) clean
	@make -C $(UTILS_DIR) clean
	@make -C $(GAME_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@echo "Fichiers objets et fichiers temporaires supprimés."

# Nettoyage complet (objets + exécutable + bibliothèques)
fclean: clean
	rm -f $(NAME)
	@make -C $(GNL_DIR) fclean
	@make -C $(UTILS_DIR) fclean
	@make -C $(GAME_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@echo "Exécutable et bibliothèques supprimés."

# Recompilation complète
re: fclean all

# Règles d'usage
.PHONY: all clean fclean re