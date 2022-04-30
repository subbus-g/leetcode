// https://leetcode.com/problems/last-stone-weight/
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
	//brue force approach
	int lastStoneWeight(vector<int> &stones)
	{
		//while there are atleast 2 stones
		while (stones.size() >= 2)
		{
			//sort the weights
			sort(begin(stones), end(stones));

			//remove highest weight stone, second highest weighted stone
			//and assign to s1,s2
			int s1 = *stones.erase(end(stones) - 1);
			int s2 = *stones.erase(end(stones) - 1);

			//if they are not equal
			if (s1 != s2)
			{
				//add the new weight
				stones.push_back(abs(s1 - s2));
			}
		}
		//return left stone weight , if there are no stones return 0
		return stones.size() ? stones.front() : 0;
	}
	// TC : Θ(n * nlogn) = O(n^2 logn) in worst case
	//while loop runs atmost n times and sorting takes O(n logn)
	// SC : Θ(1) in worst case
	// where n = number of stones
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("0.1-in.txt", "r", stdin);
	freopen("0.3-out.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Solution sol;
	int t;
	cin >> t;
	while (t--)
	{
		string ip1;
		cin >> ip1;

		istringstream iss1(ip1);

		vector<int> v1;

		iss1 >> v1;

		cout << sol.lastStoneWeight(v1);
		cout << endl;
	}
}
