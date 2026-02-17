#pragma once
#include <rack.hpp>

using namespace rack;

extern Plugin* pluginInstance;

// Forward declarations
struct SplineOscillatorModule;
struct SplineOscillatorWidget;

// IDs for modules and parameters
enum ModuleIds {
	SPLINE_OSCILLATOR_ID,
	NUM_MODULES
};

enum ParamIds {
	FREQ_PARAM,
	TENSION_PARAM,
	GRAVITY_PARAM,
	SHADOW_DEPTH_PARAM,
	RANDOMIZE_RATE_PARAM,
	NUM_PARAMS
};

enum InputIds {
	PITCH_INPUT,
	TENSION_INPUT,
	GRAVITY_INPUT,
	SHADOW_INPUT,
	NUM_INPUTS
};

enum OutputIds {
	WAVE_OUTPUT,
	NUM_OUTPUTS
};

enum LightIds {
	NUM_LIGHTS
};