// https://leetcode.com/problems/plus-one/
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
	int maxProduct(vector<int> &nums)
	{
		priority_queue<int> pq(nums.begin(), nums.end());
		int x = pq.top();
		pq.pop();
		return (x - 1) * (pq.top() - 1);
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
		vector<int> nums;
		cin >> nums;
		cout << sol.maxProduct(nums);
	}

	return 0;
}
