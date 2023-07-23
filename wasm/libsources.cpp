#include "emscripten.h"
#include "emscripten/bind.h"
#include "seeds.h"

EMSCRIPTEN_BINDINGS (mymodule) {
  emscripten::register_vector<std::string>("StringList");
  emscripten::function("GetSeeds", &Seeds::GetSeeds);

}