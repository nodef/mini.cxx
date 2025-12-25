#include <iostream>
#include <mini.h>
#include <string>


int main() {
  // Create an INI file instance
  mINI::INIFile file("example3.ini");

  // Create a structure to hold the data
  mINI::INIStructure ini;

  // Populate the structure with initial data
  ini["server"]["host"] = "127.0.0.1";
  ini["server"]["port"] = "8080";
  ini["database"]["user"] = "admin";
  ini["database"]["password"] = "password123";
  ini["database"]["timeout"] = "30";

  // Write the structure to the file
  file.generate(ini, true);

  std::cout << "Generated example3.ini with server and database configurations."
            << std::endl;

  // Read the file back
  if (file.read(ini)) {
    std::cout << "Analyzing example3.ini:" << std::endl;

    // Iterate through sections and keys dynamically
    for (const auto &section : ini) {
      std::cout << "[" << section.first << "]" << std::endl;
      for (const auto &key : section.second) {
        std::cout << key.first << " = " << key.second << std::endl;

        // Perform some analysis (e.g., check for sensitive data)
        if (key.first == "password") {
          std::cout << "Warning: Sensitive data found in section '"
                    << section.first << "'!" << std::endl;
        }
      }
    }
  } else {
    std::cerr << "Failed to read example3.ini" << std::endl;
  }

  return 0;
}
