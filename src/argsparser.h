#ifndef ARGSPARSER_H
#define ARGSPARSER_H

#include <ostream>
#include <cstdint>

class ArgsParser {
  private:
    const int32_t ARG_C = 4;
    const int32_t FILENAME_I = 1;
    const int32_t WORDLEN_I = 2;
    const int32_t MODE_CODE = 3;
    const int MAX_WL = 63;
    const int MIN_WL = 1;
    const char * m_Filename;
    int32_t m_WordLen;
    int32_t m_Mode_code;
    void setFilename(const char * filename) {
        m_Filename = filename;
    }
    void setWordLen(const char * wordlen_s) {
        int tmp = atoi(wordlen_s); 
        if (tmp > MAX_WL || tmp < MIN_WL) 
            throw "Incorrect word length!";
        m_WordLen = tmp; 
    }
    void setModeCode(const char * mode_code_s) {
        m_Mode_code = atoi(mode_code_s);
    }   
    void print_usage(std::ostream & out, const char * program) {
        out << "usage: " 
            << program 
            << "filename wordlength mode{1,2}" 
            << std::endl;
    }
  public:
    ArgsParser(std::ostream & out, int argc, char * argv[]) {
        try {
            if (argc != ARG_C) {
                throw "Not correct number of arguments!";   
            }
            setFilename(argv[FILENAME_I]);
            setWordLen(argv[WORDLEN_I]);
            setModeCode(argv[MODE_CODE]);
        } catch (const char * e) {
            print_usage(out, argv[0]);
            throw e;
        }
    }
    const char * getFilename() const {
        return m_Filename;
    }
    const uint32_t getWordLen() const {
        return m_WordLen; 
    }
    const uint32_t getModeCode() const {
        return m_Mode_code;
    }   
};

#endif
