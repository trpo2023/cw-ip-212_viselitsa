#define CTEST_MAIN
#include <ctest.h>
#include <viselica_lib/viselica.h>

CTEST(sortWordTest, SortsWordInAscendingOrder)
{
    char word[] = "braz";
    int count = strlen(word);

    sortWord(word, count);

    ASSERT_STR("abrz", word);
}

CTEST(sortWordTest, SortsWordInDescendingOrder)
{
    char word[] = "zrba";
    int count = strlen(word);

    sortWord(word, count);

    ASSERT_STR("abrz", word);
}

CTEST(sortWordTest, SortsWordWithRepeatedLetters)
{
    char word[] = "banana";
    int count = strlen(word);

    sortWord(word, count);

    ASSERT_STR("aaabnn", word);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}