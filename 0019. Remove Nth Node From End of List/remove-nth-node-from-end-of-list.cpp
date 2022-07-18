// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{

public:
	ListNode *sentinel = new ListNode(-1);
	void insertEnd(int x)
	{
		ListNode *ptr;
		for (ptr = sentinel; ptr->next; ptr = ptr->next)
		{
		}
		ptr->next = new ListNode(x);
	}
	void print()
	{
		if (!sentinel->next)
		{
			cout << "[]" << endl;
			return;
		}
		cout << "[" << sentinel->next->val;
		for (auto ptr = sentinel->next->next; ptr; ptr = ptr->next)
		{
			cout << "," << ptr->val;
		}

		cout << "]" << endl;
	}
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		sentinel->next = head;
		int size;
		ListNode *ptr;
		for (size = 0, ptr = sentinel->next; ptr; size++, ptr = ptr->next)
		{
		}
		// cout << size << endl;
		int position = size - n + 1;
		int i;
		for (i = 0, ptr = sentinel; ptr && i != (position - 1); i++, ptr = ptr->next)
		{
		}
		auto ntd = ptr->next;

		ptr->next = ptr->next->next;
		delete ntd;
		return sentinel->next;
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

		istringstream ll(s);
		vector<int> vec;
		ll >> vec;

		Solution sol;
		for (auto &x : vec)
		{
			sol.insertEnd(x);
		}
		sol.removeNthFromEnd(sol.sentinel->next, x);
		sol.print();
		cout << endl;
	}

	return 0;
}
