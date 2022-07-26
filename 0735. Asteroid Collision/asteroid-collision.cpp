// https://leetcode.com/problems/asteroid-collision/

#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Container = std::deque<T>>
void print_stack(std::stack<T, Container> stack)
{

	// template <typename T>
	// void print_stack(std::stack<T> stack){

	// Notice that we're working on a copy here. IMPORTANT
	std::cout << "stack of elements : [";
	while (!stack.empty())
	{
		T item = stack.top();
		std::cout << " " << item;
		stack.pop(); // Poping from a copy doesn't affect the original. We're good here.
	}
	std::cout << "]" << std::endl;
}

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
	vector<int> asteroidCollision(vector<int> &asteroids)
	{
		stack<int> stk;
		for (auto &x : asteroids)
		{
			if (stk.empty() || (stk.top() < 0 && x < 0) || (stk.top() > 0 && x > 0))
			{
				stk.push(x);
			}
			else
			{
				while (1)
				{
					if(stk.empty())
						break;
					if (abs(x) > abs(stk.top()))
					{
						stk.pop();
						stk.push(x);
					}
					else if (abs(x) == abs(stk.top()))
					{
						stk.pop();
					}
					else
					{
						break;
					}
				}
				// while (abs(x) >= abs(stk.top()))
				// {
				// 	stk.pop();
				// 	if (abs(x) > abs(stk.top()))
				// 	{
				// 		stk.push(x);
				// 	}
				// }
			}
		}
		print_stack(stk);
		return asteroids;
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
		string ip;
		cin >> ip;

		istringstream iss(ip);

		vector<int> v;

		iss >> v;
		// cout << "sdf";
		cout << sol.asteroidCollision(v);
		cout << endl;
	}

	return 0;
}
