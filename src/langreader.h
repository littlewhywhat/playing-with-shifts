#ifndef LANGREADER_H
#define LANGREADER_H

#include <fstream>
#include <string>

#include "language.h"

class LangReader {
  public: 
    void read(Language & lang, const std::string & path) {
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
};

#endif
