#include <fstream>
#include <string>

#include <iostream>

#include "language.h"
#include "langreader.h"

void LangReader::read(Language & lang, const std::string & path) const {
    std::fstream fs(path, std::ios_base::in);
    try {
        if (!fs.is_open())
            throw "Error trying to open file";
        std::string buffer;
        while (std::getline(fs, buffer)) {
            lang.add(buffer);
        }
    } catch (const char * e) {
        fs.clear();
        fs.close();
        std::cout << e << std::endl;
        throw e;
    }
}
