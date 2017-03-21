#include <fstream>
#include <string>

#include <iostream>

#include "langreader.h"
#include "language.h"

void LangReader::read(const std::string & path, Language & wordset) const {
    std::fstream fs(path, std::ios_base::in);
    try {
        if (!fs.is_open())
            throw "Error trying to open file";
        std::string buffer;
        while (std::getline(fs, buffer)) {
            wordset.insert(buffer);
        }
    } catch (const char * e) {
        fs.clear();
        fs.close();
        std::cout << e << std::endl;
        throw e;
    }
}
