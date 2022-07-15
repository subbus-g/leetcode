// https://leetcode.com/problems/intersection-of-two-arrays/
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
	// constant space approach
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
	{
		// sort the given vectors
		sort(begin(nums1), end(nums1));
		sort(begin(nums2), end(nums2));

		// create result vector to store the unique common elements
		vector<int> result;

		// for every element,x,of nums1
		for (const auto &x : nums1)
		{
			// if it is present in num2
			// but not present in unique common elements list,result
			if (binary_search(begin(nums2), end(nums2), x) && !binary_search(begin(result), end(result), x))
			{
				// add it to result
				result.push_back(x);
			}
		}
		return result;
	}
	// TC : Θ(n log m) in worst case
	// SC : Θ(1) in worst case
	// where n = size(num1), m=size(nums2)
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("0-!n.txt", "r", stdin);
	freopen("0-out.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Solution sol;
	int t;
	cin >> t;
	while (t--)
	{
		string ip1, ip2;
		cin >> ip1 >> ip2;

		istringstream iss1(ip1);
		istringstream iss2(ip2);

		vector<int> v1, v2;

		iss1 >> v1;
		iss2 >> v2;

		cout << sol.intersection(v1, v2);
		cout << endl;
	}
}
