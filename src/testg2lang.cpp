#include <cstdint>
#include <iostream>

#include "language.h"
#include "tbllanguage.h"
#include "trlanguage.h"
#include "graph2lang.h"
#include "graph.h"
#include "greader.h"

const uint32_t PATH_ID = 1;
const uint32_t LEN_ID = 2;
const uint32_t LANGUAGE_ID = 3;

const uint32_t TBL_LANG_ID = 1;
const uint32_t TR_LANG_ID = 2;

int main(int argc, char * argsv[]) {
    const char * filename = argsv[PATH_ID];
    GReader greader(filename);
    Graph graph;
    try {
        greader.read(graph);
    } catch (const char * e) {
        std::cout << e << std::endl;
        return 1;
    }
    int wordlen = std::stoi(argsv[LEN_ID]);
    int worddata_code = std::stoi(argsv[LANGUAGE_ID]);
    Language * lang;
    if (worddata_code == TBL_LANG_ID)     
        lang = new TblLanguage(wordlen);
    else
        lang = new TrLanguage(wordlen);
    Graph2Lang g2lang;
    g2lang.translate(graph, *lang);
    std::cout << *lang;
    delete lang;
    return 0;
}
