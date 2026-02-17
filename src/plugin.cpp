#include "plugin.hpp"

Plugin* pluginInstance;

void init(Plugin* p) {
    pluginInstance = p;
    p->addModel(createModel<SplineOscillatorModule, SplineOscillatorWidget>("SplineSynthesis", "SplineOscillator", "Spline Oscillator", OSCILLATOR_TAG));
}