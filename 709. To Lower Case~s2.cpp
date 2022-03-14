// https://leetcode.com/problems/to-lower-case/
#include <iostream>
#include <cctype>
using namespace std;

class Solution
{
public:
    // using built-in function
    string toLowerCase(string s)
    {
        for (auto &c : s)
        {
            c = tolower(c);
        }
        return s;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("0.1-in.txt", "r", stdin);
    freopen("0.3-out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    Solution sol;

    string s;
    cin >> s;
    cout << sol.toLowerCase(s);

    return 0;
}
