//
// Created by Quoc Minh Vu on 2017-09-29.
//

#ifndef COMP6651_ASSIGNMENT01_LEVENSHTEIN_H
#define COMP6651_ASSIGNMENT01_LEVENSHTEIN_H

#include <string>

using std::string;

class Levenshtein {
private:
public:
    Levenshtein() = delete;
    int static measureDistance(const string &source, const string &target);
};


#endif //COMP6651_ASSIGNMENT01_LEVENSHTEIN_H
