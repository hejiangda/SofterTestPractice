//    第十六题、A+B
//    Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
//    Problem Description
//    输入两个不超过整型定义的非负10进制整数A和B(<=231-1)，输出A+B的m (1 < m <10)进制数。
//    Input
//    输入格式：测试输入包含若干测试用例。每个测试用例占一行，给出m和A，B的值。
//    当m为0时输入提示结束。输入错误需要提示。
//    Output
//    输出格式：每个测试用例的输出占一行，输出A+B的m进制数。
//    Sample Input
//    8  63  1
//    100
//    Game over
//    Sample Output
//    2  60  4
//    1000000

#include <iostream>
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

string change(long long s, long long m)
{
    string ret;
    if (s == 0)
        return "0";
    while (s)
    {
        ret = to_string(s % m) + ret;
        s /= m;
    }

    return ret;
}

long long add( long long a, long long b)
{
    long long s;
    s = a + b;
    return s;
}
string result(long long m, long long a, long long b)
{
    long long s = add(a, b);
    return change(s, m);
}
// 题目给出的样例
TEST(testcase, demo)
{
    EXPECT_EQ("100", result(8, 63, 1));
    EXPECT_EQ("1000000", result(2, 60, 4));

}

struct abmres
{
    long long m;
    long long a, b;
    string result;
};
std::istream& operator >> (std::istream& is, abmres& out)
{
    is >> out.a;
    is >> out.b;
    is >> out.m;
    is >> out.result;
    return is;
}
class abmresTest : public ::testing::TestWithParam<abmres>
{
public:

};
// 总体测试
TEST_P(abmresTest, abmresT)
{
    abmres param =  GetParam();
    EXPECT_EQ(param.result, result(param.m, param.a, param.b));
}

std::ifstream abmresinputValuesFromFile("./abmres.txt");
INSTANTIATE_TEST_SUITE_P(FromFileStream,
                         abmresTest,
                         testing::ValuesIn(std::istream_iterator<abmres>(abmresinputValuesFromFile),
                                           std::istream_iterator<abmres>()));

struct absum
{
    long long a, b;
    long long  sum;
};
std::istream& operator >> (std::istream& is, absum& out)
{
    is >> out.a;
    is >> out.b;
    is >> out.sum;
    return is;
}
class absumTest : public ::testing::TestWithParam<absum>
{
public:

};
// add测试
TEST_P(absumTest, absumT)
{
    absum param =  GetParam();
    EXPECT_EQ(param.sum, add( param.a, param.b));
}

std::ifstream absuminputValuesFromFile("./absum.txt");
INSTANTIATE_TEST_SUITE_P(FromFileStream,
                         absumTest,
                         testing::ValuesIn(std::istream_iterator<absum>(absuminputValuesFromFile),
                                           std::istream_iterator<absum>()));
struct mres
{
    long long m;
    long long sum;
    string result;
};
std::istream& operator >> (std::istream& is, mres& out)
{
    is >> out.m;
    is >> out.sum;
    is >> out.result;
    return is;
}
class mresTest : public ::testing::TestWithParam<mres>
{
public:

};
// change测试
TEST_P(mresTest, mresT)
{
    mres param =  GetParam();
    EXPECT_EQ(param.result, change( param.sum, param.m));
}

std::ifstream mresinputValuesFromFile("./msumres.txt");
INSTANTIATE_TEST_SUITE_P(FromFileStream,
                         mresTest,
                         testing::ValuesIn(std::istream_iterator<mres>(mresinputValuesFromFile),
                                           std::istream_iterator<mres>()));

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
