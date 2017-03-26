//
// Created by littlewhywhat on 3/25/17.
//

#include "applicationarguments.h"

ApplicationArguments::ApplicationArguments(const uint32_t &argc, char **argv) {
    if (argc < 2)
        throw "No arguments";
    if (!is_tag(argv[1]))
        throw "First argument must be a tag";
    std::string current_tag = argv[1];
    add_tag(current_tag);
    for (uint32_t i = 2; i < argc; i++) {
        if (is_tag(argv[i])) {
            current_tag = argv[i];
            add_tag(current_tag);
        } else {
            add_option(current_tag, argv[i]);
        }
    }
}

bool ApplicationArguments::has_tag(const std::string &tag) const {
    return m_Arguments.find(tag) != m_Arguments.end();
}

void ApplicationArguments::add_option(const std::string &tag, const std::string &option) {
    m_Arguments[tag].push_back(option);
}

bool ApplicationArguments::is_tag(const std::string &val) const {
    return val.size() > 1 && val[0] == '-';
}

void ApplicationArguments::add_tag(const std::string &tag) {
    m_Arguments.insert({tag, {}});
}

bool ApplicationArguments::empty() const {
    return m_Arguments.empty();
}
