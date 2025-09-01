#!/usr/bin/env python3
# Generate customizable FdF heightmaps with sharp random peaks
import numpy as np
import random
import argparse
import sys

def generate_heightmap(width, height, target_min, target_max, num_peaks=5, output_file=None):
    """
    Generate a heightmap with sharp random peaks
    
    Args:
        width, height: Map dimensions
        target_min, target_max: Height range
        num_peaks: Number of peaks to generate
        output_file: Output filename (optional)
    """
    
    X, Y = np.meshgrid(np.arange(width), np.arange(height))
    
    # Base terrain: softer background waves with more variation
    terrain = (
        3 * np.sin(0.03 * X) +
        3 * np.cos(0.05 * Y) +
        2 * np.sin(0.02 * (X + Y)) +
        1.5 * np.cos(0.08 * (X - Y))
    )
    
    # Generate random peak locations and characteristics
    peaks = np.zeros((height, width))
    
    print(f"Generating {num_peaks} peaks...")
    
    for i in range(num_peaks):
        # Random peak center (avoid edges)
        margin = min(width, height) // 8
        cx = random.randint(margin, width - margin)
        cy = random.randint(margin, height - margin)
        
        # Random peak characteristics
        peak_height = random.uniform(0.6, 1.0)  # Vary peak heights
        peak_width = random.uniform(8, 20)      # Vary peak sharpness
        
        # Sharp peak using exponential with higher power for sharper edges
        distance_sq = (X - cx)**2 + (Y - cy)**2
        sharp_peak = peak_height * np.exp(-(distance_sq / (2 * (peak_width**2))))
        
        # Make peaks even sharper by raising to a power
        sharpness_factor = random.uniform(1.0, 2.0)
        sharp_peak = np.power(sharp_peak, sharpness_factor)
        
        # Scale the peak
        peak_scale = random.uniform(120, 200)
        peaks += peak_scale * sharp_peak
        
        print(f"  Peak {i+1}: center=({cx},{cy}), height={peak_height:.2f}, width={peak_width:.1f}, sharpness={sharpness_factor:.2f}")
    
    # Add valleys (negative peaks) for more interesting terrain
    num_valleys = max(1, num_peaks // 3)
    for i in range(num_valleys):
        cx = random.randint(margin, width - margin)
        cy = random.randint(margin, height - margin)
        valley_depth = random.uniform(0.3, 0.7)
        valley_width = random.uniform(15, 30)
        
        distance_sq = (X - cx)**2 + (Y - cy)**2
        valley = valley_depth * np.exp(-(distance_sq / (2 * (valley_width**2))))
        valley_scale = random.uniform(-60, -30)
        peaks += valley_scale * valley
        
        print(f"  Valley {i+1}: center=({cx},{cy}), depth={valley_depth:.2f}, width={valley_width:.1f}")
    
    # Add realistic noise
    noise_strength = (target_max - target_min) * 0.02  # 2% of range
    noise = np.random.normal(0, noise_strength, size=(height, width))
    
    # Combine all components
    Z = terrain + peaks + noise
    
    # Normalize to target range
    Zmin, Zmax = Z.min(), Z.max()
    Z_scaled = (Z - Zmin) / (Zmax - Zmin) * (target_max - target_min) + target_min
    Z_int = np.rint(Z_scaled).astype(int)
    
    # Generate filename if not provided
    if output_file is None:
        output_file = f"heightmap_{width}x{height}_{target_min}to{target_max}.fdf"
    
    # Save as .fdf file
    with open(output_file, "w") as f:
        for row in Z_int:
            f.write(" ".join(map(str, row.tolist())) + "\n")
    
    print(f"\nGenerated heightmap: {output_file}")
    print(f"Dimensions: {width}x{height}")
    print(f"Height range: {Z_int.min()} to {Z_int.max()}")
    print(f"Target range: {target_min} to {target_max}")

def main():
    parser = argparse.ArgumentParser(description='Generate FdF heightmaps with sharp random peaks')
    parser.add_argument('width', type=int, help='Map width')
    parser.add_argument('height', type=int, help='Map height')
    parser.add_argument('--min', type=int, default=-40, help='Minimum height (default: -40)')
    parser.add_argument('--max', type=int, default=190, help='Maximum height (default: 190)')
    parser.add_argument('--peaks', type=int, default=5, help='Number of peaks (default: 5)')
    parser.add_argument('--output', '-o', type=str, help='Output filename (optional)')
    parser.add_argument('--seed', type=int, help='Random seed for reproducible results')
    
    args = parser.parse_args()
    
    # Validate arguments
    if args.width <= 0 or args.height <= 0:
        print("Error: Width and height must be positive integers")
        sys.exit(1)
    
    if args.min >= args.max:
        print("Error: Minimum height must be less than maximum height")
        sys.exit(1)
    
    if args.peaks <= 0:
        print("Error: Number of peaks must be positive")
        sys.exit(1)
    
    # Set random seed if provided
    if args.seed is not None:
        random.seed(args.seed)
        np.random.seed(args.seed)
        print(f"Using random seed: {args.seed}")
    
    # Generate the heightmap
    generate_heightmap(args.width, args.height, args.min, args.max, args.peaks, args.output)

if __name__ == "__main__":
    main()