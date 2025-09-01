NAME = fdf

# ASCII Art Display
define WIREFRAME_ART
	@echo "$(GREEN)"
	@echo "              ╔════════════════════════════╗"
	@echo "              ║    ◆─────◆─────◆─────◆     ║"
	@echo "              ║    │╲    │    ╱│    ╱│     ║"
	@echo "              ║    │ ╲   │   ╱ │   ╱ │     ║"
	@echo "              ║    ◆──╲◆╱───◆╱───◆╱──◆     ║"
	@echo "              ║    │   ╱│╲  ╱│╲  ╱│  │     ║"
	@echo "              ║    │  ╱ │ ╲╱ │ ╲╱ │  │     ║"
	@echo "              ║    ◆─────◆─────◆─────◆     ║"
	@echo "              ╚════════════════════════════╝"
	@echo "$(RESET)"
	@echo "$(CYAN)        ✧･ﾟ: *✧･ﾟ:* 3D TERRAIN VISUALIZER *:･ﾟ✧*:･ﾟ✧$(RESET)"
	@echo ""
endef

# Colors for terminal output
CYAN := \033[36m
MAGENTA := \033[35m
GREEN := \033[32m
YELLOW := \033[33m
RED := \033[31m
BLUE := \033[34m
RESET := \033[0m

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = build
LIB_DIR = lib

# Source files ( find src/ -name '*.c' | sed 's/src/\$(SRC_DIR)/' )
SRC = $(SRC_DIR)/parser/get_next_line/get_next_line.c \
	$(SRC_DIR)/parser/get_next_line/get_next_line_utils.c \
	$(SRC_DIR)/parser/validator.c \
	$(SRC_DIR)/parser/parser.c \
	$(SRC_DIR)/parser/map_builder.c \
	$(SRC_DIR)/parser/map_builder_utils.c \
	$(SRC_DIR)/parser/color_parser.c \
	$(SRC_DIR)/utils/ft_strncmp.c \
	$(SRC_DIR)/utils/ft_isdigit.c \
	$(SRC_DIR)/utils/ft_split.c \
	$(SRC_DIR)/utils/ft_atoi.c \
	$(SRC_DIR)/renderer/renderer.c \
	$(SRC_DIR)/renderer/colors.c \
	$(SRC_DIR)/renderer/color_utils.c \
	$(SRC_DIR)/renderer/color_negative.c \
	$(SRC_DIR)/renderer/color_positive.c \
	$(SRC_DIR)/renderer/color_manager.c \
	$(SRC_DIR)/renderer/projection.c \
	$(SRC_DIR)/renderer/line_drawing.c \
	$(SRC_DIR)/renderer/wireframe.c \
	$(SRC_DIR)/renderer/wireframe_utils.c \
	$(SRC_DIR)/renderer/animated_wireframe.c \
	$(SRC_DIR)/renderer/animation_utils.c \
	$(SRC_DIR)/renderer/animation_cleanup.c \
	$(SRC_DIR)/ft_bzero.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/events.c \
	$(SRC_DIR)/events/key_handlers.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/display.c



# Object files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc

# Optional window dimension overrides
ifdef WINDOW_WIDTH
	WINDOW_WIDTH_FLAG = -DWINDOW_WIDTH=$(WINDOW_WIDTH)
endif

ifdef WINDOW_HEIGHT
	WINDOW_HEIGHT_FLAG = -DWINDOW_HEIGHT=$(WINDOW_HEIGHT)
endif

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -g $(WINDOW_WIDTH_FLAG) $(WINDOW_HEIGHT_FLAG)
LINKING = -L$(LIB_DIR)/minilibx-linux -lmlx_Linux -L$(LIB_DIR)/ft_printf -lftprintf -L/usr/lib -I$(LIB_DIR)/minilibx-linux -lXext -lX11 -lm -lz

# Library directories and files
MLX_DIR = $(LIB_DIR)/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

PRINTF_DIR = $(LIB_DIR)/ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

# All libraries that need to be built
LIBS = $(MLX_LIB) $(PRINTF_LIB)

all: $(NAME)
	$(WIREFRAME_ART)
	@echo "$(GREEN)🎉 FdF Wireframe Engine successfully compiled! 🎉$(RESET)"
	@echo "$(YELLOW)📖 Usage: ./fdf <map_file.fdf>$(RESET)"
	@echo "$(BLUE)🎮 Controls: WASD (move), Arrows (zoom/rotate), F/G (x-axis), J/H (y-axis), Q/E (z-scale), C (colors), P (projection), SPACE (animation)$(RESET)"
ifdef WINDOW_WIDTH
	@echo "$(CYAN)📏 Window Width: $(WINDOW_WIDTH)px$(RESET)"
endif
ifdef WINDOW_HEIGHT
	@echo "$(CYAN)📏 Window Height: $(WINDOW_HEIGHT)px$(RESET)"
endif
	@echo "$(MAGENTA)💡 Build with custom dimensions: make WINDOW_WIDTH=800 WINDOW_HEIGHT=600$(RESET)"
	@echo ""

# Build minilibx
$(MLX_LIB):
	make -C $(MLX_DIR)

# Build ft_printf
$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LIBS) $(OBJ_DIR) $(OBJ)
	@echo "$(MAGENTA)🔗 Linking wireframe engine components...$(RESET)"
	@echo "$(CYAN)   ╭─────────────────────────────────────────────╮"
	@echo "   │  🧩 Assembling 3D rendering pipeline...     │"
	@echo "   │  ⚡ Optimizing Bresenham line algorithms... │"
	@echo "   │  🎨 Configuring color gradient systems...   │"
	@echo "   │  🎮 Initializing interactive controls...    │"
	@echo "   ╰─────────────────────────────────────────────╯$(RESET)"
	$(CC) $(OBJ) $(CFLAGS) $(LINKING) -o $(NAME)
	@echo "$(GREEN)✅ Wireframe engine core successfully assembled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fdf.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(LIB_DIR)/minilibx-linux -I$(PRINTF_DIR) -c $< -o $@

clean:
	@echo "$(YELLOW)🧹 Cleaning build artifacts...$(RESET)"
	@echo "$(CYAN)   ╭─ Removing object files ──╮"
	@echo "   │    🗑️  .o files cleared    │"
	@echo "   │    📁 Build dirs cleaned   │"
	@echo "   ╰────────────────────────────╯$(RESET)"
	rm -rf $(OBJ_DIR)
	make clean -C $(MLX_DIR)
	make clean -C $(PRINTF_DIR)
	@echo "$(GREEN)✨ Workspace cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)💣 Full cleanup initiated...$(RESET)"
	@echo "$(MAGENTA)   ╭─ Destroying executables ─╮"
	@echo "   │    💥 Binary obliterated   │"
	@echo "   │    🔥 Cache incinerated    │"
	@echo "   ╰────────────────────────────╯$(RESET)"
	rm -rf $(NAME)
	make clean -C $(MLX_DIR)
	make fclean -C $(PRINTF_DIR)
	@echo "$(GREEN)🎯 Complete destruction achieved!$(RESET)"

re: 
	@echo "$(MAGENTA)"
	@echo "        ███████╗ ██████╗ ███████╗"
	@echo "        ██╔════╝ ██╔══██╗██╔════╝"
	@echo "        █████╗   ██║  ██║█████╗  "
	@echo "        ██╔══╝   ██║  ██║██╔══╝  "
	@echo "        ██║      ██████╔╝██║     "
	@echo "        ╚═╝      ╚═════╝ ╚═╝     "
	@echo "$(RESET)"
	@echo "$(RED)        🔥 PHOENIX PROTOCOL - FdF REBORN! 🔥$(RESET)"
	@echo "$(CYAN)    ╔══════════════════════════════════════╗"
	@echo "    ║  ⚡ Obliterating old build artifacts   ║"
	@echo "    ║  🏗️  Reconstructing wireframe engine   ║"  
	@echo "    ║  ✨ Reforging 3D visualization magic  ║"
	@echo "    ╚══════════════════════════════════════╝$(RESET)"
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
