RACK_PLUGIN_MANIFEST = 1
SLUG = SplineSynthesis
VERSION = 0.1.0

# Build flags for VCV Rack
CXXFLAGS = -std=c++14 -fPIC -I/path/to/VCV/includes
LDFLAGS = -shared -o $(BUILD_DIR)/plugin.dylib
