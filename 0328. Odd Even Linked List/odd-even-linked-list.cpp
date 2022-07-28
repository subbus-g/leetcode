// https://leetcode.com/problems/odd-even-linked-list/

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
	ListNode *oddEvenList(ListNode *head) // O(n) - time, O(1) - memory
	{
		// if the number of nodes is 0 or 1
		// return the same list
		if (!head || !head->next)
		{
			return head;
		}
		// if the number of nodes of nodes is greather than 1

		ListNode *even_head, *p, *q;
		even_head = head->next;

		// chain odd nodes with odd nodes,even nodes with even nodes
		for (p = head, q = even_head; p->next && q->next; p = p->next, q = q->next)
		{
			p->next = p->next->next;
			q->next = q->next->next;
		}
		// link the odd chain with the even chain
		p->next = even_head;

		return head;
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
		cin >> s;

		istringstream iss(s);
		vector<int> vec;
		iss >> vec;

		LinkedList ll;
		for (auto &x : vec)
		{
			ll.insertEnd(x);
		}

		Solution sol;
		ll.sentinel->next = sol.oddEvenList(ll.sentinel->next);
		ll.print();
		cout << endl;
	}

	return 0;
}
