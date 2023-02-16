#include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    if (s.size() == 0)
        return true;

    int len = s.size();
    for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - 1 - i])
            return false;

    return true;
}

string longestPalindrome(string s)
{
    if (isPalindrome(s))
        return s;
    string longest("");

    int r, l;

    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        r = i;
        while (r < len && s[r] == s[i])
        {
            r++;
        }

        l = i - 1;
        while (r < len && l >= 0 && s[r] == s[l])
        {
            r++;
            l--;
        }

        string sub = s.substr(l + 1, r - (l + 1));
        if (sub.size() > longest.size())
        {
            longest = sub;
        }
    }

    return longest;
}

// string longestPalindrome(string s)
// {
//     if (isPalindrome(s))
//         return s;

//     string s1 = s.substr(1, s.size() - 1);
//     string s2 = s.substr(0, s.size() - 1);

//     string lp1 = longestPalindrome(s1);
//     string lp2 = longestPalindrome(s2);
//     if (lp1.size() > lp2.size())
//         return lp1;
//     else
//         return lp2;
// }

int main()
{
    cout << longestPalindrome("aacabdkacaa") << endl;
}