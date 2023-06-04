// Copyright 2021 NNTU-CS
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>

#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::string words;
  BST<std::string> peace;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
  } else {
    while (!file.eof()) {
      char sym = tolower(file.get());
      if (isalpha(sym)) {
        words += sym;
      } else {
        if (!words.empty()) {
          peace.add(words);
        }
        words.clear();
      }
    }
  }
  file.close();
  return peace;
}
