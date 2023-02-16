#include <iostream>

using namespace std;

int main()
{
    string s = "Hello";
    string t = s.substr(0, 0);

    cout << s[0, 3] << endl;
}