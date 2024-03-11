#include <bits/stdc++.h>

#include "proj2_bigin.cpp"// import .cpp file where class functions are defined

using namespace std;

int main()//driver code
{
    Bigint one;
    Bigint two;
    cin >> one;//initialise two numbers in array
    cin >> two;
    Bigint t;

    cout << "Adiition result: ";
    t = one + two;

    cout << "Subtraction result: ";
    t = one - two;
    out << endl;

    int a = one > two;
    cout << endl;

    a = one < two;
    if (a == 1)
        cout << endl;

    a = one != two;
    if (a == 1)
        cout << endl;

    a = one == two;
    if (a == 1)
        cout << endl;
}