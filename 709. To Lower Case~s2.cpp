// https://leetcode.com/problems/to-lower-case/
#include <iostream>
#include <cctype>
using namespace std;
// time complexity : O(s.size())
// space complexity : O(1)
class Solution
{
public:
    // using range for + built-in function tolower
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
