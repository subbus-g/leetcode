// https://leetcode.com/problems/to-lower-case/
#include <bits/stdc++.h>
using namespace std;
// time complexity : O(s.size())
// space complexity : O(1)
class Solution
{
public:
    string toLowerCase(string s)
    {
        for(auto &c:s)
        {
            if(c>='A' && c<='Z')
            {
                //calcutating distance of c from 'A' and traveling that distance from 'a'
                c = (c - 'A') + 'a';
            }
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
