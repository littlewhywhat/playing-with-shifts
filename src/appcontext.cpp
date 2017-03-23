//
// Created by vaivorom on 3/23/17.
//

#include "appcontext.h"

AppContext & AppContext::get() {
    static AppContext context;
    return context;
}
