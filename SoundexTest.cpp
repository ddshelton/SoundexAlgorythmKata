#include "Soundex.h"
#include <gmock/gmock.h>
using ::testing::Eq;

class SoundexEncoding: public testing::Test{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    //Arrange

   //Act

   //Assert
   ASSERT_THAT (soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZeroToEnsureThreeDigits)
{
    //Arrange

    //Act

    //Assert
    ASSERT_THAT (soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits)
{
    //Arrange

    //Act

    //Assert
    ASSERT_THAT (soundex.encode("Ab"), Eq("A100"));
    ASSERT_THAT (soundex.encode("Ac"), Eq("A200"));
    ASSERT_THAT (soundex.encode("Ad"), Eq("A300"));
    ASSERT_THAT (soundex.encode("Al"), Eq("A400"));
    ASSERT_THAT (soundex.encode("Am"), Eq("A500"));
    ASSERT_THAT (soundex.encode("Ar"), Eq("A600"));
    ASSERT_THAT (soundex.encode("Ap"), Eq("A100"));
    ASSERT_THAT (soundex.encode("Ar"), Eq("A600"));
}

TEST_F(SoundexEncoding, IgnoreNonAlphabetics)
{
    //Arrange

    //Act

    //Assert
    ASSERT_THAT (soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits)
{
    //Arrange

    //Act

    //Assert
    ASSERT_THAT (soundex.encode("Acdl"), Eq("A234"));
}





/*
 *
 * The correct value can be found as follows:
1. Retain the first letter of the name and drop all other occurrences of a, e, i, o, u, y, h, w.
2. Replace consonants with digits as follows (after the first letter):
b, f, p, v → 1
c, g, j, k, q, s, x, z → 2
d, t → 3
l → 4
m, n → 5
r → 6
3. If two or more letters with the same number are adjacent in the original name (before step 1),
 only retain the first letter; also two letters with the same number separated by 'h' or 'w' are coded as a single number,
 whereas such letters separated by a vowel are coded twice. This rule also applies to the first letter.
4. If you have too few letters in your word that you can't assign three numbers, append with zeros until there are three numbers.
 If you have more than 3 letters, just retain the first 3 numbers.
*/