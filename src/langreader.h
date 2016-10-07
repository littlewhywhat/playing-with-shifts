#ifndef LANGREADER_H
#define LANGREADER_H

#include <fstream>
#include <string>

#include "language.h"

class LangReader {
  public: 
    void read(Language & lang, const std::string & path) {
        std::fstream fs(path);
        if (!fs.is_open())
            throw "Error trying to open file";
        std::string buffer;
        while (std::getline(fs, buffer)) {
            lang.add(buffer);
        }
    }
};

#endif
