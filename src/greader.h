#ifndef GREADER_H
#define GREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

#include "graph.h"

class GReader {
  private:
    const char DELIM = ',';
    std::string m_Filename;
  public: 
    void setFilename(const std::string & filename) { 
        m_Filename = filename;
    }
    void read(Graph & g) const {
        std::fstream fs(m_Filename, std::ios::in);
    //    std::cout << m_Filename << std::endl;
        try {
            if (!fs) {
                fs.clear();
                throw "Error while openning file";
            }
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
      //          std::cout << n1 << ',' << n2 << ',' << lbl << std::endl;
                g.addEdge(n1, n2, lbl);
            }
        } catch (const char * e) {
            fs.close();
            throw e;
        }
    }
    friend std::ostream & operator << (std::ostream & out, const GReader & src) {
     //   out << src.m_Filename;
        return out;
    }
};

#endif
