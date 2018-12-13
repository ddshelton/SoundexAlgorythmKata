#include "gmock/gmock.h"
#include <iostream>
#include <string>
using namespace std;

/*
 *
 * The correct value can be found as follows:
Retain the first letter of the name and drop all other occurrences of a, e, i, o, u, y, h, w.
Replace consonants with digits as follows (after the first letter):
b, f, p, v → 1
c, g, j, k, q, s, x, z → 2
d, t → 3
l → 4
m, n → 5
r → 6
If two or more letters with the same number are adjacent in the original name (before step 1), only retain the first letter; also two letters with the same number separated by 'h' or 'w' are coded as a single number, whereas such letters separated by a vowel are coded twice. This rule also applies to the first letter.
If you have too few letters in your word that you can't assign three numbers, append with zeros until there are three numbers. If you have more than 3 letters, just retain the first 3 numbers.
 */

class Soundex
{

public:
    string encode(const string& word) const
    {
        return word;
    }
};

using ::testing::Eq;
TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    //Arrange
   Soundex soundex;

   //Act
   auto encode = soundex.encode("A");

   //Assert
   ASSERT_THAT (encode, Eq("A"));
}

