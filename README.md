# FdF Wireframe Terrain Visualizer

## Overview
FdF is a 3D wireframe renderer for 42cursus, built with C and MiniLibX. It visualizes terrain maps from .fdf files, supporting advanced camera controls, multiple projections, earth-like coloring, and smooth animation. The codebase is modular, memory-safe, and free of global variables.

## Features
- **Flexible Camera Controls**: Move, zoom, rotate on all axes
- **Multiple Projections**: Isometric, Orthographic, Perspective
- **Earth-like Coloring**: Toggle between original and terrain-based colors
- **Animated Wireframe**: Water-flow and center-outward effects
- **Adaptive Z-Scale**: Fine and coarse depth control
- **Bonus**: Camera, projections, coloring, animation, and more
- **Norminette & Valgrind**: Fully compliant and memory-leak free

## Demo
![Wireframe Animation Demo](video/whole_world_animation_4x_speed.gif)

## File Structure
```
src/
├── parser/
│   ├── map_builder.c         # Main map parsing logic
│   ├── map_builder_utils.c   # Helper functions for parsing
│   ├── color_parser.c        # Hex color parsing
│   └── ...                   # get_next_line, validator, etc.
├── renderer/
│   ├── color_manager.c       # Color scheme logic
│   ├── wireframe.c           # Bresenham, drawing
│   ├── animated_wireframe.c  # Animation effects
│   └── ...                   # projection, utils, etc.
├── events/
│   ├── key_handlers.c        # Key event logic
│   └── ...                   # event loop
├── utils/                    # String, memory, error helpers
├── main.c                    # Entry point
├── display.c                 # Window/image management
└── ...
```

## Build & Run
```sh
make
./fdf <map_file.fdf>
# Custom window size:
make WINDOW_WIDTH=1200 WINDOW_HEIGHT=900
```

## Controls
- **W/A/S/D**: Move camera
- **Arrow Keys**: Zoom (Up/Down), Rotate Z (Left/Right)
- **F/G**: Rotate X-axis
- **J/H**: Rotate Y-axis
- **Q/E**: Z-scale (adaptive speed)
- **0**: Reset Z-scale
- **C**: Toggle color scheme (original/terrain)
- **P**: Toggle projection (Iso/Ortho/Persp)
- **SPACE**: Toggle wireframe animation
- **ESC**: Exit

## Color System
- **Default**: Uses explicit colors from FDF file, or white if unspecified
- **Terrain Mode (C key)**: Always applies earth-like colors based on elevation

## Projections
- **Isometric**: Classic 3D wireframe
- **Orthographic**: Top-down, no perspective
- **Perspective**: Realistic depth scaling

## Memory & Code Quality
- No global variables
- All dynamic memory is freed
- Norminette: All files ≤5 functions, all functions ≤25 lines
- Valgrind: No leaks

## Bonus Features
- Camera controls
- Multiple projections
- Earth-like coloring
- Animated wireframe
- Adaptive Z-scale



## Authors
- esouhail - El Houssain Souhail
