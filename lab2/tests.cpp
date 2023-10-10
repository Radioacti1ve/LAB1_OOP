#include <gtest/gtest.h>
#include "BitString.h"

TEST(test_1, Everything) {
    BitString a("1011");
    BitString b("1001");

    //размеры
    size_t asize = a.GetSize();
    size_t checksize1 = 4;
    size_t bsize = b.GetSize();
    size_t checksize2 = 4;

    //строки?..
    unsigned char* stra = a.GetStr();
    unsigned char* strb = b.GetStr();
    unsigned char checkstr1[] = {'1','0','1','1'}, checkstr2[] = {'1','0','0','1'};

    //перевод в 10-ую систему счисления
    int achange = a.change_10();
    int bchange = b.change_10();
    int ansa = 11;
    int ansb = 9;

    //арифметические операции
    std::string sum = a.plus(b);
    std::string ans_sum = "10100";
    std::string minus = a.minus(b);
    std::string ans_minus = "10";

    //операции сравнения
    std::string larg = a.larger(b);
    std::string ans_larg = "true";
    std::string smal = a.smaller(b);
    std::string ans_smal = "false";
    std::string eq = a.equal(b);
    std::string ans_eq = "false";

    
    //операции с битовыми строками
    std::string tmp1 = a._and(b);
    std::string tmp2 = a._or(b);
    std::string tmp3 = a._xor(b);
    std::string tmp4 = a._not();


   std::string ans_and = "1001" ;
   std::string ans_or = "1011";
   std::string ans_xor = "0010";
   std::string ans_not = "0100";

    //проверка
    ASSERT_EQ(asize, checksize1);
    ASSERT_EQ(bsize, checksize2);
    for(size_t i = 0; i < asize; ++i) {
        ASSERT_EQ(stra[i], checkstr1[i]);
    }

    for(size_t i = 0; i < bsize; ++i) {
        ASSERT_EQ(strb[i], checkstr2[i]);
    }

    ASSERT_EQ(sum, ans_sum);
    ASSERT_EQ(minus, ans_minus);
    
    ASSERT_EQ(larg, ans_larg);
    ASSERT_EQ(smal, ans_smal);
    ASSERT_EQ(eq, ans_eq);

    ASSERT_EQ(tmp1, ans_and);
    ASSERT_EQ(tmp2, ans_or);
    ASSERT_EQ(tmp3, ans_xor);
    ASSERT_EQ(tmp4, ans_not);

}

TEST(test_2, Everything) {
    BitString a("1010011");
    BitString b("1111111111");

    //размеры
    size_t asize = a.GetSize();
    size_t checksize1 = 7;
    size_t bsize = b.GetSize();
    size_t checksize2 = 10;

    //строки?..
    unsigned char* stra = a.GetStr();
    unsigned char* strb = b.GetStr();
    unsigned char checkstr1[] = {'1','0','1','0','0','1','1'}, checkstr2[] = {'1','1','1','1','1','1','1','1','1','1'};

    //перевод в 10-ую систему счисления
    int achange = a.change_10();
    int bchange = b.change_10();
    int ansa = 83;
    int ansb = 1023;

    //арифметические операции
    std::string sum = a.plus(b);
    std::string ans_sum = "10001010010";
    std::string minus = a.minus(b);
    std::string ans_minus = "negative number";

    //операции сравнения
    std::string larg = a.larger(b);
    std::string ans_larg = "false";
    std::string smal = a.smaller(b);
    std::string ans_smal = "true";
    std::string eq = a.equal(b);
    std::string ans_eq = "false";

    
    //операции с битовыми строками
    std::string tmp1 = a._and(b);
    std::string tmp2 = a._or(b);
    std::string tmp3 = a._xor(b);
    std::string tmp4 = a._not();


   std::string ans_and = "Строки имеют разную длину" ;
   std::string ans_or = "Строки имеют разную длину";
   std::string ans_xor = "Строки имеют разную длину";
   std::string ans_not = "0101100";

    //проверка
    ASSERT_EQ(asize, checksize1);
    ASSERT_EQ(bsize, checksize2);
    for(size_t i = 0; i < asize; ++i) {
        ASSERT_EQ(stra[i], checkstr1[i]);
    }

    for(size_t i = 0; i < bsize; ++i) {
        ASSERT_EQ(strb[i], checkstr2[i]);
    }

    ASSERT_EQ(sum, ans_sum);
    ASSERT_EQ(minus, ans_minus);
    
    ASSERT_EQ(larg, ans_larg);
    ASSERT_EQ(smal, ans_smal);
    ASSERT_EQ(eq, ans_eq);

    ASSERT_EQ(tmp1, ans_and);
    ASSERT_EQ(tmp2, ans_or);
    ASSERT_EQ(tmp3, ans_xor);
    ASSERT_EQ(tmp4, ans_not);

}

TEST(test_3, Everything) {
    BitString a("100");
    BitString b("101");

    //размеры
    size_t asize = a.GetSize();
    size_t checksize1 = 3;
    size_t bsize = b.GetSize();
    size_t checksize2 = 3;

    //строки?..
    unsigned char* stra = a.GetStr();
    unsigned char* strb = b.GetStr();
    unsigned char checkstr1[] = {'1','0','1'}, checkstr2[] = {'1','0','1'};

    //перевод в 10-ую систему счисления
    int achange = a.change_10();
    int bchange = b.change_10();
    int ansa = 4;
    int ansb = 5;

    //арифметические операции
    std::string sum = a.plus(b);
    std::string ans_sum = "1001";
    std::string minus = a.minus(b);
    std::string ans_minus = "negative number";

    //операции сравнения
    std::string larg = a.larger(b);
    std::string ans_larg = "false";
    std::string smal = a.smaller(b);
    std::string ans_smal = "true";
    std::string eq = a.equal(b);
    std::string ans_eq = "false";

    
    //операции с битовыми строками
    std::string tmp1 = a._and(b);
    std::string tmp2 = a._or(b);
    std::string tmp3 = a._xor(b);
    std::string tmp4 = a._not();


   std::string ans_and = "100" ;
   std::string ans_or = "101";
   std::string ans_xor = "001";
   std::string ans_not = "011";

    //проверка
    ASSERT_EQ(asize, checksize1);
    ASSERT_EQ(bsize, checksize2);
    for(size_t i = 0; i < asize; ++i) {
        ASSERT_EQ(stra[i], checkstr1[i]);
    }

    for(size_t i = 0; i < bsize; ++i) {
        ASSERT_EQ(strb[i], checkstr2[i]);
    }

    ASSERT_EQ(sum, ans_sum);
    ASSERT_EQ(minus, ans_minus);
    
    ASSERT_EQ(larg, ans_larg);
    ASSERT_EQ(smal, ans_smal);
    ASSERT_EQ(eq, ans_eq);

    ASSERT_EQ(tmp1, ans_and);
    ASSERT_EQ(tmp2, ans_or);
    ASSERT_EQ(tmp3, ans_xor);
    ASSERT_EQ(tmp4, ans_not);

}

TEST(test_4, InvalidArgument) {
    ASSERT_THROW(BitString("123141aaa"), std::invalid_argument);
}

TEST(test_5, InvalidArgument) {
    ASSERT_THROW(BitString("kak je ya ustal uje"), std::invalid_argument);
}

TEST(test_6, InvalidArgument) {
    ASSERT_THROW(BitString("-_- ^-^ <3"), std::invalid_argument);
}