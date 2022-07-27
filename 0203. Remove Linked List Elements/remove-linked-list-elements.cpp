// https://leetcode.com/problems/remove-linked-list-elements/

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
class LinkedList
{
public:
	ListNode *sentinel = new ListNode(-1);

public:
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
	void insertEnd(int x)
	{
		ListNode *ptr;
		for (ptr = sentinel; ptr->next; ptr = ptr->next)
		{
		}
		ptr->next = new ListNode(x);
	}
};
class Solution
{
public:
	ListNode *removeElements(ListNode *head, int val) // time - O(N), memory - O(1)
	{
		// attach sentinel before head
		auto sentinel = new ListNode(-1, head);

		ListNode *pre, *cur;
		for (pre = nullptr, cur = sentinel; cur; pre = cur, cur = cur->next)
		{
			if (cur->val == val)
			{
				auto node_to_delete = cur;
				pre->next = cur->next;
				cur = pre;
				delete node_to_delete;
			}
		}

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

		istringstream iss(s);
		vector<int> vec;
		iss >> vec;

		LinkedList ll;
		for (auto &x : vec)
		{
			ll.insertEnd(x);
		}

		Solution sol;
		ll.sentinel->next = sol.removeElements(ll.sentinel->next, x);
		ll.print();
		cout << endl;
	}

	return 0;
}
