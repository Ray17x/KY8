#include "Utils/console.hpp"
#include <filesystem>
#include <juce_core/juce_core.h>
using namespace RC;
namespace fs = std::filesystem;

/*
    Lets just grab a file for now and play it, then try to adjust DSP later
*/

int main() {
    fs::path input_path = ""; // Save input file path here
    if (input_path.empty() || !fs::exists(input_path)) { // Check if input file path is empty or exists
        error("No input file provided");
        return EXIT_FAILURE;
    }

    // Play the song
        

}
