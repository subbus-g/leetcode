// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

// for cin>>vector
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{

	T x;
	char sentinel; // for '['
	in >> sentinel;
	while (in >> x)
	{
		if (in.peek() == ',') // check if the next character is a comma and ignore it
			in.ignore();
		v.push_back(x);
	}
	return in;
}

// for cout<<vector
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
	out << "[";
	for_each(begin(v), end(v) - 1, [&](const auto &element)
			 { out << element << ","; });
	out << v.back() << "]" << endl;
	return out;
}
class Solution
{
public:
	bool isValid(string s)
	{
		map<char, char> closed_pareentheses = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
		stack<char> stk;
		for (auto &c : s)
		{
			//if  c  is open parentheses
			if (closed_pareentheses.find(c) != closed_pareentheses.end())
			{
				stk.push(c);
			}
			//if c is closed parenthesis
			//check if  c matches to existing opening parenthesis
			else if (!stk.empty() && c == closed_pareentheses[stk.top()])
			{
				stk.pop();
			}
			else
			{
				return false;
			}
		}
		return stk.empty();
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
		cout << boolalpha << sol.isValid(s) << endl;
		cout << endl;
	}

	return 0;
}
