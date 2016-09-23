#include <iostream>

#include "app.h"

void print_usage(const char * program) {
    std::cout << "usage: " << program 
              << "filename wordlength mode{1,2}" 
              << std::endl;
}

const int FILENAME_I = 1;
const int WORDLEN_I = 2;
const int MODE_CODE = 3;

int main (int argc, char * argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return 1;   
    }
    const char * filename = argv[FILENAME_I];
    const int wordlen = atoi(argv[WORDLEN_I]);
    if (wordlen > 63 || wordlen <= 0) {
        print_usage(argv[0]);
        return 1;
    }
    const int mode_code = atoi(argv[MODE_CODE]);
    
    try {
        App app(std::cout, filename, wordlen, mode_code);
        app.run();
    } catch (const char * e) {
        std::cout << e << std::endl;
        return 1;
    }   
    return 0;
}
