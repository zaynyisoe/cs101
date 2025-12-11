#ifndef READCLASS_H
#define READCLASS_H

#include <string>
#include <vector>

class ReadClass {
private:
    std::string filename;
    std::vector<std::string> classNames;

public:
    ReadClass(const std::string &fname);
    void process();
    void printResult() const;
};

#endif
