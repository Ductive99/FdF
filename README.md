### Potential Improvements
- Don't use get_next_line instead try to read the entire file at once in a buffer saving time and operations

### Advised File Structure
```
src/
├── parser/
│   ├── file_io.c       # open, read, close
│   ├── validation.c    # format checking
│   ├── tokenizer.c     # split lines, parse numbers
│   └── map_builder.c   # fill t_map structure
├── math/
│   ├── projections.c   # 3D -> 2D transformations
│   └── transformations.c # rotate, scale, translate
├── renderer/
│   ├── mlx_wrapper.c   # MLX abstraction
│   └── line_drawing.c  # Bresenham, etc.
└── utils/
    ├── memory.c        # safe malloc/free
    └── error.c         # error handling
```

### TO-DO
 - Add Camera Settings              (BONUS +15%)    (DONE)
    - Zoom in and out - Translation - Rotation
 - Include another projection       (BONUS +5%)     (DONE - Isometric/Orthographic/Perspective)
 - Add another bonus of your choice (BONUS +5%)     (DONE - Earth-like coloring)
 - Add Depth modifications                          (DONE) 
 - Add flip (DONE)

 - Check why maps/pentenegpos.fdf looks flat        (FIXED)

### Controls
- **W/A/S/D**: Move camera (W=up, S=down, A=left, D=right)
- **Up/Down Arrow**: Zoom in/out
- **Left/Right Arrow**: Rotate around Z-axis
- **F Key**: Rotate around X-axis forward (pitch - like nodding down)
- **G Key**: Rotate around X-axis backward (pitch - like nodding up)
- **J Key**: Rotate around Y-axis clockwise (yaw - like turning head right)
- **H Key**: Rotate around Y-axis counter-clockwise (yaw - like turning head left)
- **Q/E Keys**: Decrease/Increase Z-scale (adaptive speed)
- **0 Key**: Reset Z-scale to default (1.0)
- **C Key**: Toggle color scheme (original/earth-like colors)
  - **Default mode**: Uses original colors from FDF file, or white if no colors specified
  - **Terrain mode**: Always uses earth-like terrain colors based on elevation
- **P Key**: Toggle projection type (Isometric/Orthographic/Perspective)
- **ESC**: Exit program

### Z-Scale Control System
The depth control has been enhanced for maximum precision:
- **Q/E Keys**: Adaptive speed adjustment
  - Large steps (±0.1) when Z-scale > 1.0
  - Medium steps (±0.01) when Z-scale is 0.1-1.0  
  - Fine steps (±0.001) when Z-scale < 0.1
- **R/T Keys**: Ultra-fine adjustment (±0.0001)
- **0 Key**: Instant reset to default (1.0)
- **Minimum**: Can go as low as 0.001 (nearly flat)
- **Maximum**: No upper limit

### Earth-Like Coloring
When enabled with the **C** key, the visualization uses realistic colors:
- **Deep Blue**: Deep water (lowest elevations)
- **Light Blue/Cyan**: Shallow water  
- **Yellow**: Beach/sand (around sea level)
- **Green**: Vegetation (low to medium elevations)
- **Dark Green**: Dense forests (higher elevations)
- **Brown/White**: Mountain peaks (highest elevations)

### Projection Types
Press the **P** key to cycle through three different projection modes:

#### Isometric Projection (Default)
- Classic 3D wireframe appearance with 30° angles
- Provides excellent depth perception while maintaining proportions
- Full rotation support with F/J keys
- Best for detailed height visualization and general 3D exploration

#### Orthographic Projection  
- Top-down technical view without perspective distortion
- All parallel lines remain parallel regardless of distance
- Ideal for precise measurements and map analysis
- No depth scaling - maintains true proportions

#### Perspective Projection
- Realistic depth scaling where distant objects appear smaller
- Creates the most natural-looking 3D visualization
- Simulates how the human eye perceives depth
- Objects closer to the camera appear larger than those farther away


t1
t2
pyramide
julia
elem-fract
7essira