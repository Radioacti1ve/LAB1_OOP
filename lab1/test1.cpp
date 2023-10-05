#include <gtest/gtest.h>
#include "func.h"

TEST(test_01, basic_test_set) {
    int n = 2;
    char old_value = 'a';
    char new_value = 'o';
    std::string message = "Vader said: No, I am your father!";
    std::string answer = "Vader soid: No, I am your fother!";

    ASSERT_TRUE(func(n, old_value, new_value, message)==answer);
}

TEST(test_02, basic_test_set) {
    int n = 3;
    char old_value = 'c';
    char new_value = 'k';
    std::string message = "Hecco worlkd ccc kok lol ccc";
    std::string answer = "Hecco worlkd kcc kok lol kcc";

    ASSERT_TRUE(func(n, old_value, new_value, message)==answer);
}

TEST(test_03, basic_test_set) {
    int n = -10;
    char old_value = 'a';
    char new_value = 'b';
    std::string message = "aksdkj asjdklj lol sadnjam sand";
    std::string answer = "aksdkj asjdklj lol sadnjam sand";

    ASSERT_TRUE(func(n, old_value, new_value, message)==answer);
}

TEST(test_04, basic_test_set) {
    int n = 1;
    char old_value = 'o';
    char new_value = 'l';
    std::string message = "hello world sad city behaviour";
    std::string answer = "helll wlrld sad city behavilur";

    ASSERT_TRUE(func(n, old_value, new_value, message)==answer);
}

TEST(test_05, basic_test_set) {
    int n = 5;
    char old_value = 'p';
    char new_value = 'P';
    std::string message = "Hi";
    std::string answer = "Hi";

    ASSERT_TRUE(func(n, old_value, new_value, message)==answer);
}

TEST(test_06, basic_test_set) {
    int n = 4;
    char old_value = 'q';
    char new_value = 'h';
    std::string message = "quiet quiclky qqq quest queue";
    std::string answer = "quiet quiclky qhq quest queue";

    ASSERT_TRUE(func(n, old_value, new_value, message)==answer);
}

TEST(test_07, basic_test_set) {
    int n = 10;
    char old_value = 't';
    char new_value = 'j';
    std::string message = "ajsdlaslatttttttttttttttttttt";
    std::string answer = "ajsdlaslatttttttttjtttttttttj";

    ASSERT_TRUE(func(n, old_value, new_value, message)==answer);
}

TEST(test_08, basic_test_set) {
    int n = 0;
    char old_value = 'q';
    char new_value = 'l';
    std::string message = "qqqqqqqqqqqqqqqqqqqqq";
    std::string answer = "qqqqqqqqqqqqqqqqqqqqq";

    ASSERT_TRUE(func(n, old_value, new_value, message)==answer);
}

int main(int argc, char * argw[]) {
    testing::InitGoogleTest(&argc, argw);
    return RUN_ALL_TESTS();
}
