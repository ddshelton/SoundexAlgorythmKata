//
// Created by davidshelton on 12/13/2018.
//

#ifndef FIRSTEXAMPLE_SOUNDEX_H
#define FIRSTEXAMPLE_SOUNDEX_H

#include <iostream>
#include <string>
using namespace std;
static const size_t MaxCodeLength(4);
class Soundex
{
    string zeroPad(const string& word)const;
    string head(const string& word) const;
    string tail(const string& word) const;
    string encodeDigits(const string& word) const;
    string encodeDigit(char letter) const;
public:

    string encode(const string& word) const;

};

#endif //FIRSTEXAMPLE_SOUNDEX_H
