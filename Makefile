# Nom de l'exécutable final
NAME = Solong

# Compilateur et options
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Sous-dossiers contenant des Makefiles
GNL_DIR = GetNextLine
UTILS_DIR = Utils

# Bibliothèques compilées
GNL_LIB = $(GNL_DIR)/get_next_line.a
UTILS_LIB = $(UTILS_DIR)/Utils.a

# Fichiers source et objets du programme principal
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Inclusion des headers
INCLUDES = -I $(GNL_DIR) -I $(MATH_DIR) -I $(UTILS_DIR)

# Règle principale pour construire l'exécutable
all: $(GNL_LIB) $(UTILS_LIB) $(NAME)

# Construction de l'exécutable final
$(NAME): $(OBJS) $(GNL_LIB) $(MATH_LIB) $(UTILS_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(GNL_DIR) -lget_next_line \
	-L$(UTILS_DIR) -lutils -o $(NAME)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Construction des bibliothèques (appel des sous-Makefiles)
$(GNL_LIB):
	@make -C $(GNL_DIR)

$(UTILS_LIB):
	@make -C $(UTILS_DIR)

# Nettoyage des fichiers objets et des bibliothèques
clean:
	rm -f $(OBJS)
	@make -C $(GNL_DIR) clean
	@make -C $(UTILS_DIR) clean

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	@make -C $(GNL_DIR) fclean
	@make -C $(UTILS_DIR) fclean

# Reconstruction complète
re: fclean all

.PHONY: all clean fclean re