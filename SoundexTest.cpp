#include <gmock/gmock.h>
#include "Soundex.h"
using namespace testing;
// Create a class fixture
class SoundexEncoding: public testing::Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits)
{
    // Note: Require does not fail the test, assert does.
    // Best practice states to only use EXPECT_ when
    // developing the code, not in production.
//     EXPECT_THAT(soundex.encode("Ap"), Eq("A100"));
//    EXPECT_THAT(soundex.encode("Ax"), Eq("A200"));
//    EXPECT_THAT(soundex.encode("Ar"), Eq("A600"));
    ASSERT_THAT(soundex.encode("Ap"), Eq("A100"));
    ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
    ASSERT_THAT(soundex.encode("Ar"), Eq("A600"));
}

TEST_F(SoundexEncoding, IgnoreNonAlphabetics)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

// DISABLED_ will not run the test.
// use it when you need to Refactor your code
// then, when you are ready, "enable" your test
TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitLengthToFourCharacters)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, CombineDuplicateEncodings)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encodeDigit('b'), Eq(soundex.encodeDigit('f')));
    ASSERT_THAT(soundex.encodeDigit('x'), Eq(soundex.encodeDigit('g')));
    ASSERT_THAT(soundex.encodeDigit('d'), Eq(soundex.encodeDigit('t')));

    ASSERT_THAT(soundex.encode("Abfxgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, UpperCaseFirstLetter)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoreVowelsLikeLetters)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYwWcdl"), Eq("B234"));

}

TEST_F(SoundexEncoding, IgnoreCaseWhenEncodingConsonants)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("BCDL"), soundex.encode("Bcdl"));

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