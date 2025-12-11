#include "ReadClass.h"

int main() {
    ReadClass rc("main.cpp");   // file to read
    rc.process();
    rc.printResult();

    return 0;
}
