#include <iostream>
#pragma warning(disable: 4996)
using namespace std;
#include"myString.h"
int main()
{
    cout << boolalpha;
    myString str1("Leyla");
    myString str2("Nigar");
    myString appended=str1.append(" Hello");
    cout << appended.print() << endl;
    cout << str1.at(2) << endl;
    cout << str1.back() << endl;
    cout << str1.capacity() << endl;
}

