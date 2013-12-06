#include <stdio.h>
#include <assert.h>
#include <string.h>

int my_strcmp(const char *str1, const char*str2)
{
    int ret;
    assert(str1 && str2);
    while(!(ret = *str1 - *str2) && *str1++ && *str2++);
    return (ret < 0) ? -1 : !!ret;
}

void test1()
{
    char *str1 = "A";
    char *str2 = "F";
    assert(my_strcmp(str1, str2) == strcmp(str1, str2));
}

void test2()
{
    char *str1 = "a";
    char *str2 = "A";
    assert(my_strcmp(str1, str2) == strcmp(str1, str2));
}

void test3()
{
    char *str1 = "computer";
    char *str2 = "compare";
    assert(my_strcmp(str1, str2) == strcmp(str1, str2));
}

void test4()
{
    char *str1 = "computer";
    char *str2 = "com";
    assert(my_strcmp(str1, str2) == strcmp(str1, str2));
}

void test5()
{
    char *str1 = "computer";
    char *str2 = "computer";
    assert(my_strcmp(str1, str2) == strcmp(str1, str2));
}

void test6()
{
    char *str1 = "";
    char *str2 = "computer";
    assert(my_strcmp(str1, str2) == strcmp(str1, str2));
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}

