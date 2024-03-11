#include <bits/stdc++.h>
#include "proj2_bigint.h" // import .h file where class functions are declared

using namespace std;

Bigint::Bigint() // default construtor
{
    for (int i = 0; i < 5; i++)
    {
        v[i] = 0;
    }
}

Bigint::Bigint(int n0, int n1) // parameterised constructor
{
    v[0] = n0;
    v[1] = n1;
    v[2] = 0;
    v[3] = 0;
    v[4] = 0;
}

Bigint::Bigint(int n0, int n1, int n2) // parameterised constructor
{
    v[0] = n0;
    v[1] = n1;
    v[2] = n2;
    v[3] = 0;
    v[4] = 0;
}

Bigint::Bigint(int n0, int n1, int n2, int n3) // parameterised constructor
{
    v[0] = n0;
    v[1] = n1;
    v[2] = n2;
    v[3] = n3;
    v[4] = 0;
}

Bigint::Bigint(int n0, int n1, int n2, int n3, int n4) // parameterised constructor
{
    v[0] = n0;
    v[1] = n1;
    v[2] = n2;
    v[3] = n3;
    v[4] = n4;
}

ifstream inp("proj2_test.txt");     // opening of input file
ofstream out("proj2_test_out.txt"); // opening of output file

Bigint Bigint ::operator+(Bigint &a) // operator overloading for +
{
    int carry = 0;
    Bigint obj;
    string temp;

    for (int i = 0; i < 5; i++)
    {
        obj.v[i] = v[i] + a.v[i] + carry;

        if (to_string(obj.v[i]).length() > 9)
        {
            temp = to_string(obj.v[i]);
            carry = stoi(temp.substr(0, 1)); // calculating carry
            obj.v[i] = stoi(temp.substr(1));
        }
    }

    string check;
    check = to_string(obj.v[4]) + to_string(obj.v[3]) + to_string(obj.v[2]) + to_string(obj.v[1]) + to_string(obj.v[0]);
    out << "Addition result: ";
    if (check.length() > 45)
    {
        cout << "Computation for addition is not possible" << endl;
        out << "Computation for addition is not possible" << endl;
        return obj;
    }
    else
    {
        cout << obj << endl;
        out << endl;
        return obj;
    }
}

Bigint Bigint::operator-(Bigint &b) // operator overloading for -
{
    int bor = 0;
    Bigint sub;
    string temp;
    string s1, s2;
    s1 = to_string(v[4]) + to_string(v[3]) + to_string(v[2]) + to_string(v[1]) + to_string(v[0]);
    s2 = to_string(b.v[4]) + to_string(b.v[3]) + to_string(b.v[2]) + to_string(b.v[1]) + to_string(b.v[0]);
    if (s1.length() < s2.length())
    {
        cout << "can't subtract the numbers as the result is providing signed integer";
        return sub;
    }
    for (int i = 0; i < 5; i++)
    {
        if (b.v[i] < 0 || v[i] < 0)
        {
            cout << "Wrong input!! Enter a unsigned integer" << endl;
            out << "Wrong input!! Enter a unsigned integer" << endl;
            return sub;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        sub.v[i] = v[i] - b.v[i] - bor;
        if (sub.v[i] < 0)
        {
            temp = to_string(sub.v[i]);
            bor = 1; // calculating borrow
            int n = temp.length();
            sub.v[i] = sub.v[i] + pow(10, 9) + 1;
        }
        else
        {
            bor = 0;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (b.v[i] < 0 || sub.v[i] < 0)
        {
            cout << "Subtraction can't be performed as it does not result in usingned integer" << endl;
            out << "Subtraction can't be performed as it does not result in usingned integer" << endl;
            return sub;
        }
    }
    string check;
    check = to_string(sub.v[4]) + to_string(sub.v[3]) + to_string(sub.v[2]) + to_string(sub.v[1]) + to_string(sub.v[0]);
    out << "Subtraction result: ";
    cout << sub << endl;
    return sub;
}

int Bigint::operator>(Bigint &num) // operator overloading for >
{
    string num1, num2;
    int c = 0;
    num1 = to_string(v[4]) + to_string(v[3]) + to_string(v[2]) + to_string(v[1]) + to_string(v[0]);
    num2 = to_string(num.v[4]) + to_string(num.v[3]) + to_string(num.v[2]) + to_string(num.v[1]) + to_string(num.v[0]);

    if (num1.length() > num2.length())
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << setfill('0') << setw(9) << v[i];
            out << setfill('0') << setw(9) << v[i]; // writing to file
        }
        cout << " is greater than ";
        out << " is greater than ";
        for (int i = 4; i >= 0; i--)
        {
            cout << setfill('0') << setw(9) << num.v[i];
            out << setfill('0') << setw(9) << num.v[i];
        }
        out << endl;
        return 1;
    }
    else if (num1.length() < num2.length()) // if number of zeros are more in 1st number but its is greater than 2nd number
    {
        for (int i = 4; i >= 0; i--)
        {
            if (v[i] > num.v[i])
            {
                c = 1;
                break;
            }
        }
        if (c == 1)
        {
            for (int i = 4; i >= 0; i--)
            {
                cout << setfill('0') << setw(9) << v[i];
                out << setfill('0') << setw(9) << v[i];
            }
            cout << " is greater than ";
            out << " is greater than ";
            for (int i = 4; i >= 0; i--)
            {
                cout << setfill('0') << setw(9) << num.v[i];
                out << setfill('0') << setw(9) << v[i];
            }
            out << endl;
            return 1;
        }
    }

    return 0;
}

int Bigint::operator==(Bigint &num) // operator overloading for ==
{
    string num1, num2;
    int c = 0;
    num1 = to_string(v[4]) + to_string(v[3]) + to_string(v[2]) + to_string(v[1]) + to_string(v[0]);
    num2 = to_string(num.v[4]) + to_string(num.v[3]) + to_string(num.v[2]) + to_string(num.v[1]) + to_string(num.v[0]);

    if (num1 == num2 && num1.length() == num2.length()) // checks that the numbers to be equal in all sense
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << setfill('0') << setw(9) << v[i];
            out << setfill('0') << setw(9) << v[i];
        }
        cout << " is equal to ";
        out << " is equal to ";
        for (int i = 4; i >= 0; i--)
        {
            cout << setfill('0') << setw(9) << num.v[i];
            out << setfill('0') << setw(9) << num.v[i];
        }
        out << endl;
        return 1;
    }
    return 0;
}

int Bigint::operator!=(Bigint &num) // operator overloading for !=
{
    string num1, num2;
    int c = 0;
    num1 = to_string(v[4]) + to_string(v[3]) + to_string(v[2]) + to_string(v[1]) + to_string(v[0]);
    num2 = to_string(num.v[4]) + to_string(num.v[3]) + to_string(num.v[2]) + to_string(num.v[1]) + to_string(num.v[0]);

    if (num1 != num2 || num1.length() != num2.length()) // either the length or numbers or not equal it puts that both numbers are not equal
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << setfill('0') << setw(9) << v[i];
            out << setfill('0') << setw(9) << v[i];
        }
        cout << " is not equal to ";
        out << " is not equal to ";
        for (int i = 4; i >= 0; i--)
        {
            cout << setfill('0') << setw(9) << num.v[i];
            out << setfill('0') << setw(9) << num.v[i];
        }
        out << endl;
        return 1;
    }
    return 0;
}

int Bigint::operator<(Bigint &num) // operator overloading for <
{
    string num1, num2;
    int c = 0;
    num1 = to_string(v[4]) + to_string(v[3]) + to_string(v[2]) + to_string(v[1]) + to_string(v[0]);
    num2 = to_string(num.v[4]) + to_string(num.v[3]) + to_string(num.v[2]) + to_string(num.v[1]) + to_string(num.v[0]);

    if (num1.length() < num2.length())
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << setfill('0') << setw(9) << v[i];
            out << setfill('0') << setw(9) << v[i];
        }
        cout << " is lesser than ";
        out << " is lesser than ";
        for (int i = 4; i >= 0; i--)
        {
            cout << setfill('0') << setw(9) << num.v[i];
            out << setfill('0') << setw(9) << num.v[i];
        }
        return 1;
    }
    else if (num1.length() < num2.length()) // if number of zeros are more in 1st number but its is less than 2nd number
    {
        for (int i = 4; i >= 0; i--)
        {
            if (v[i] < num.v[i])
            {
                c = 1;
                break;
            }
        }
        if (c == 1)
        {
            for (int i = 4; i >= 0; i--)
            {
                cout << setfill('0') << setw(9) << v[i];
                out << setfill('0') << setw(9) << v[i];
            }
            cout << " is lesser than ";
            out << " is lesser than ";
            for (int i = 4; i >= 0; i--)
            {
                cout << setfill('0') << setw(9) << num.v[i];
                out << setfill('0') << setw(9) << v[i];
            }
            out << endl;
            return 1;
        }
    }

    return 0;
}

ostream &operator<<(ostream &show, Bigint &a) // operator overloading for <<
{
    string num1;
    num1 = to_string(a.v[4]) + to_string(a.v[3]) + to_string(a.v[2]) + to_string(a.v[1]) + to_string(a.v[0]);
    for (int i = 4; i >= 0; i--)
    {
        show << setfill('0') << setw(9) << a.v[i]; // output to console
        out << setfill('0') << setw(9) << a.v[i];  // output to file
    }

    return show;
}

istream &operator>>(istream &in, Bigint &b)
{
    string num1;
    getline(inp, num1);

    if (num1.length() > 45)
    {
        cout << "Computation not possible" << endl;
        return in;
    }

    int n = num1.length();
    int n1 = num1.length();

    if (n >= 9) // input the numbers into the array v
    {
        int q = n % 9;
        int re = n / 9;
        int ct = 0;
        int k = 0;
        string temp;
        for (int i = n - 1; i >= 0; i--)
        {
            temp = num1[i] + temp;
            ct++;
            if (ct == 9) // checking that the number stored is of length 9 or not if yes store it in the respective indices
            {
                b.v[k] = stoi(temp);
                temp = "";
                ct = 0;
                k++;
            }
        }
        if (ct > 0)
        {
            b.v[k] = stoi(temp);
        }
    }
    else
    {
        b.v[0] = stoi(num1);
    }
    return in;
}
