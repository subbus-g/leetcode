// https://leetcode.com/problems/rotate-array/

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
	void rotate(vector<int> &nums)
	{
		int stash = nums[nums.size() - 1];
		for (int i = nums.size() - 1; i > 0; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[0] = stash;
	}
	void rotate(vector<int> &nums, int k)
	{
		while (k--)
		{
			rotate(nums);
		}
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("0-!n.txt", "r", stdin);
	freopen("0-out.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		int x;
		cin >> s >> x;

		istringstream iss(s);
		vector<int> vec;
		iss >> vec;

		Solution sol;
		sol.rotate(vec, x);
		cout << vec;
		cout << endl;
	}

	return 0;
}
