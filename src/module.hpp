# SplineOscillatorModule

class SplineOscillatorModule : public Module {
public:
    enum ParamIds {
        PARAM_FREQUENCY,
        PARAM_WAVEFORM,
        // Add more parameters as needed
        NUM_PARAMS
    };

    enum InputIds {
        INPUT_CV_FREQUENCY,
        // Add more CV inputs as needed
        NUM_INPUTS
    };

    enum OutputIds {
        OUTPUT_AUDIO,
        // Add more outputs as needed
        NUM_OUTPUTS
    };

    SplineOscillatorModule() {
        config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS);
        configParam(PARAM_FREQUENCY, 20.f, 2000.f, 440.f, "Frequency");
        configParam(PARAM_WAVEFORM, 0.f, 1.f, 0.f, "Waveform");
    }

    void process(const ProcessArgs &args) override {
        // Implement the processing code, handling CV inputs for frequency
        float frequency = inputs[INPUT_CV_FREQUENCY].getVoltage();
        // Use frequency to influence the oscillator's behavior
        // Output audio signal logic would be here
    }
};


# SplineOscillatorWidget

struct SplineOscillatorWidget : ModuleWidget {
    SplineOscillatorWidget(SplineOscillatorModule *module) {
        setModule(module);
        box.size = Vec(15 * 5, 380);
        // Layout the UI with knobs and ports

        addParam(createParam<LEDButton>(mm2px(5.0), mm2px(20.0), module->PARAM_FREQUENCY));
        addInput(createInput<PJ301MPort>(mm2px(10.0), mm2px(75.0), module->INPUT_CV_FREQUENCY));
        addOutput(createOutput<PJ301MPort>(mm2px(10.0), mm2px(150.0), module->OUTPUT_AUDIO));
        // Add more UI elements as needed
    }
};