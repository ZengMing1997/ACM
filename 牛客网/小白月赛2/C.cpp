#include <bits/stdc++.h>
using namespace std;
map<string,int>M;
int main()
{
    int t;
    scanf("%d",&t);
    M["algorithm"] = 1, M["bitset"] = 1, M["cctype"] = 1, M["cerrno"] = 1, M["clocale"] = 1,
    M["cmath"] = 1, M["complex"] = 1, M["cstdio"] = 1, M["cstdlib"] = 1, M["cstring"] = 1, M["ctime"] = 1, M["deque"] = 1
    , M["exception"] = 1, M["fstream"] = 1, M["functional"] = 1, M["limits"] = 1, M["list"] = 1, M["map"] = 1, M["iomanip"] = 1
    , M["ios"] = 1, M["iosfwd"] = 1, M["iostream"] = 1, M["istream"] = 1, M["ostream"] = 1, M["queue"] = 1, M["set"] = 1, M["sstream"] = 1, 
    M["stack"] = 1, M["stdexcept"] = 1, M["streambuf"] = 1, M["string"] = 1, M["utility"] = 1, M["vector"] = 1, M["cwchar"] = 1, M["cwctype"] = 1;
    while(t--)
    {
        string a;
        cin>>a;
        if(M[a]) puts("Qian");
        else puts("Kun");
    }
}