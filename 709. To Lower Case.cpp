// https://leetcode.com/problems/to-lower-case/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string toLowerCase(string s)
    {
        for(auto &c:s)
        {
            if(c>='A' && c<='Z')
            {
                //calculate offset(relative postion of alphabet) like 1 for A, 2 for B ....
                int offset = c - ('A' - 1);

                //add relative position to the character before 'a' like ('a' - 1) + 2 for offset 2 ('B')
                c = ('a' - 1) + offset;
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
