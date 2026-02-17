# SplineSynthesis - VCV Rack Plugin

A unique VCV Rack plugin featuring an innovative spline-based oscillator with physics-driven waveform deformation.

## Features

### Spline Oscillator Module
- **Physical Dynamics**: Waveform treated as a flexible entity governed by tension and gravity
- **Random Point Generation**: Two randomized points in a coordinate plane form the basis of waveform generation
- **Shadow Point Calculation**: A third "shadow point" is computed based on distance calculations between the primary points
- **Gravity-Based Deformation**: The shadow point pulls the interpolation curve downward, creating organic, evolving waveforms
- **Catmull-Rom Spline Interpolation**: Smooth curve interpolation between control points

## Parameters

- **Frequency**: Base oscillator frequency (pitch control)
- **Tension**: Controls the stiffness of the waveform (affects shadow point pull strength)
- **Gravity**: Physical gravity strength affecting downward deformation
- **Shadow Depth**: How deeply the shadow point influences the final curve
- **Randomize Rate**: Speed at which the random points are recalculated

## Inputs

- **Pitch**: 1V/Oct pitch control
- **Tension**: Modulation input for tension parameter
- **Gravity**: Modulation input for gravity parameter
- **Shadow**: Modulation input for shadow depth

## Outputs

- **Wave**: Main oscillator waveform output

## Installation

1. Clone this repository
2. Install VCV Rack SDK
3. Run `make` to build the plugin
4. The plugin will be installed to your VCV Rack plugins directory

## Building

```bash
make
make install
```

## Development

The core synthesis algorithm is implemented in `src/SplineOscillator.cpp`