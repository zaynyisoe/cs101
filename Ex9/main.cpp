#include "ReadClass.h"
#include <fstream>
#include <iostream>
#include <sstream>

ReadClass::ReadClass(const std::string &fname) : filename(fname) {}

void ReadClass::process() {
    std::ifstream fin(filename);
    if (!fin) {
        std::cout << "Cannot open file: " << filename << std::endl;
        return;
    }

    std::string word;
    while (fin >> word) {
        if (word == "class") {
            std::string className;
            fin >> className;

            // remove trailing '{' or ':' if attached
            while (!className.empty() &&
                  (className.back() == '{' || className.back() == ':'))
            {
                className.pop_back();
            }

            classNames.push_back(className);
        }
    }
}

void ReadClass::printResult() const {
    std::cout << "Found " << classNames.size() << " class(es):\n";
    for (const auto &c : classNames) {
        std::cout << c << "\n";
    }
}
