#include <iostream>
#include <mini.h>
#include <string>


int main() {
  // Create an INI file instance
  mINI::INIFile file("example2.ini");

  // Create a structure to hold the data
  mINI::INIStructure ini;

  // Populate the structure with initial data
  ini["user"]["name"] = "John Doe";
  ini["user"]["email"] = "john.doe@example.com";
  ini["preferences"]["theme"] = "dark";
  ini["preferences"]["notifications"] = "enabled";

  // Write the structure to the file
  file.generate(ini, true);

  std::cout << "Generated example2.ini with user data." << std::endl;

  // Modify the data
  ini["user"]["email"] = "john.new@example.com";
  ini["preferences"]["theme"] = "light";

  // Add new data
  ini["preferences"]["language"] = "en-US";

  // Remove a key
  ini["preferences"].remove("notifications");

  // Write the updated structure back to the file
  file.write(ini, true);

  std::cout << "Updated example2.ini with new preferences." << std::endl;

  // Display the updated data
  for (const auto &section : ini) {
    std::cout << "[" << section.first << "]" << std::endl;
    for (const auto &key : section.second) {
      std::cout << key.first << " = " << key.second << std::endl;
    }
  }

  return 0;
}
