#include "app.h"

int main(int argc, char * argsv[]) {
    App app;
    try {
        app.run(argc, argsv);
    } catch (const char * e) {
        std::cout << e << std::endl;
    }
    return 0;
}
