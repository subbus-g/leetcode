// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	string removeDuplicates(string s) // time - O(s.size()), memory - O(s.size())
	{
		stack<char> stk;
		for (auto &c : s)
		{
			if (!stk.empty() && stk.top() == c)
			{
				stk.pop();
			}
			else
			{
				stk.push(c);
			}
		}
		string output;
		while (!stk.empty())
		{
			output = stk.top() + output;
			stk.pop();
		}
		return output;
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("0-!n.txt", "r", stdin);
	freopen("0-out.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);

	Solution sol;

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << sol.removeDuplicates(s) << endl;
		cout << endl;
	}

	return 0;
}
