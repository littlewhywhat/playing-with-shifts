#include <fstream>
#include <string>
#include <iostream>

#include "greader.h"
#include "graph.h"

void GReader::read(Graph & g, const std::string & path) const {
    std::fstream fs(path, std::ios::in);
    try {
        if (!fs) 
            throw "Error while openning file";
        std::string buffer;
        if (!std::getline(fs,buffer))
            throw "Error while reading size in file";
        g.setSize(std::stoi(buffer));
        int n1, n2, lbl;
        while (std::getline(fs, buffer, DELIM)) {
            n1 = std::stoi(buffer);
            if (!std::getline(fs, buffer, DELIM))
                throw "Error while reading n1 in file";
            n2 = std::stoi(buffer);
            if (!std::getline(fs, buffer))
                throw "Error while reading n2 in file";
            lbl = buffer.at(buffer.size() - 1);
            g.addEdge(n1, n2, lbl);
        }
    } catch (const char * e) {
        fs.clear();
        fs.close();
        std::cout << e << std::endl;
        throw e;
    }
}
