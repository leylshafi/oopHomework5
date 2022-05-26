#include <iostream>
using namespace std;
#include"myString.h"
int main()
{
    cout << boolalpha;
    /*myString str = "Hello";
    myString str1="HSello";
    myString appended = str.append(" Leyla");
    cout<<appended.print();*/
    /*myString str(5, "Nigar");
    cout << str.print();*/

    myString str("Hello");
    myString str2("World");
    //myString sub = str.subString(1, 4);
    //cout << sub.print();
    str.swap(str2);
    // cout << str.print();
    // cout << str2.print();

    myString name = "Eminem";
     
     name.erase(4, 2);
     cout << name.print() << endl;








    //cout << str.front();
    //cout << str.at(1) << endl;
    //cout << str.capacity() << endl;
    //cout << str.rfind('l');
    //cout<<str.print()<<endl;
    //cout << str1.empty() << endl;
    //myString newStr = str.append(" Leyla");
    // cout << newStr.print() << endl;
    // cout << newStr.size() << endl;
    // cout << newStr.capacity() << endl;
    /*cout << str.capacity() << endl;
    str.shrink_to_fit();
    cout << str.capacity() << endl;*/
    // str.resize(5);
    // cout << str.print() << endl;
    // cout << str.size() << endl;
    // str.clear();
    // cout << str.print() << endl;
    // cout << str.size() << endl;
    // cout << str.capacity() << endl;

    //cout<<str.compare(str1);

}

