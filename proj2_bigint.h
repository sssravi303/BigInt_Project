#include <bits/stdc++.h>
using namespace std;

class Bigint
{
private:
    int res[5];

public:
    int v[5];
    Bigint();
    Bigint(int n0, int n1);
    Bigint(int n0, int n1, int n2);
    Bigint(int n0, int n1, int n2, int n3);
    Bigint(int n0, int n1, int n3, int n4, int n5);

    Bigint operator+(Bigint &a);
    Bigint operator-(Bigint &b);
    int operator>(Bigint &num);
    int operator<(Bigint &num);
    int operator!=(Bigint &num);
    int operator==(Bigint &num);
    int operator<=(Bigint &num);
    int operator>=(Bigint &num);
    friend ostream &operator<<(ostream &out, Bigint &a);
    friend istream &operator>>(istream &in, Bigint &a);
};
