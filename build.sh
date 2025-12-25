#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -f "mini/ini.h" ]; then return; fi
URL="https://github.com/metayeti/mINI/raw/refs/heads/master/src/mini/ini.h"
FILE="mini/ini.h"

# Download the release
if [ ! -f "$FILE" ]; then
  echo "Downloading $FILE from $URL ..."
  mkdir -p mini
  curl -L "$URL" -o "$FILE"
  echo ""
fi
}


# Test the project
test() {
echo "Running 01-basic-read-write.cxx ..."
clang++ -std=c++17 -I. -o 01.exe examples/01-basic-read-write.cxx       && ./01.exe && echo -e "\n"
echo "Running 02-advanced-manipulation.cxx ..."
clang++ -std=c++17 -I. -o 02.exe examples/02-advanced-manipulation.cxx  && ./02.exe && echo -e "\n"
echo "Running 03-dynamic-iteration.cxx ..."
clang++ -std=c++17 -I. -o 03.exe examples/03-dynamic-iteration.cxx      && ./03.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
