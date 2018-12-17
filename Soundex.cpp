//
// Created by davidshelton on 12/13/2018.
//
#include <unordered_map>
#include "Soundex.h"

    /**
    * @brief pad word to 4 digits
    * @param word  - input string
    * @return  - padded string
    */
string Soundex::zeroPad(const string& word)const
{
   auto zerosNeeded = 4 - word.length();
    return word + string(zerosNeeded, '0');
}
/**
 * @brief Encode string to Soundex Algorithm
 * @param word - string to code
 * @return - encoded string
 */
string Soundex::encode(const string& word) const
{
    return zeroPad(head(word) + encodeDigits(word));
}

/**
 * Extract first character of string
 * @param word - input string
 * @return - first letter of string "head"
 *
 */
string Soundex::head(const string &word) const {
    return word.substr(0, 1);
    // return std::string();
}

string Soundex::encodeDigits(const string &word) const {
    if(word.length() > 1)
    {
        return encodeDigit(word[1]);
    }
    else
    {
        return "";
    }
    //return std::string();
}

string Soundex::encodeDigit(char letter) const
{
    const unordered_map<char, string> encoding
            {
                    {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
                    {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"},
                    {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
                    {'d', "3"}, {'t', "3"},
                    {'l', "4"},
                    {'m', "5"}, {'n', "5"},
                    {'r', "6"}
            };
    auto it = encoding.find(letter);

    //if you reach the end of the map there is no match
    // In this case, return an empty string
    return it == encoding.end() ? "" : it -> second;

}
