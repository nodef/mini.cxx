#include <iostream>
#include <mini.h>
#include <string>


int main() {
  // Create an INI file instance
  mINI::INIFile file("example1.ini");

  // Create a structure to hold the data
  mINI::INIStructure ini;

  // Populate the structure
  ini["settings"]["volume"] = "75";
  ini["settings"]["brightness"] = "50";

  // Write the structure to the file
  file.generate(ini, true);

  std::cout << "Generated example1.ini with initial settings." << std::endl;

  // Read the file back
  if (file.read(ini)) {
    std::cout << "Read from example1.ini:" << std::endl;
    for (const auto &section : ini) {
      std::cout << "[" << section.first << "]" << std::endl;
      for (const auto &key : section.second) {
        std::cout << key.first << " = " << key.second << std::endl;
      }
    }
  } else {
    std::cerr << "Failed to read example1.ini" << std::endl;
  }

  return 0;
}
