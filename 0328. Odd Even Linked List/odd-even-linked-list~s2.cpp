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
		if (!head)
		{
			return head;
		}
		//find the end of odd chain
		ListNode *odd_chain_end;
		for (odd_chain_end = head; odd_chain_end->next && odd_chain_end->next->next; odd_chain_end = odd_chain_end->next->next)
		{
		}

		//if there are even number of nodes there will be 1 even node after odd chain end node
		auto last_even_node = (odd_chain_end->next ? odd_chain_end->next: nullptr);

		auto tail = odd_chain_end;

		//keep adding even nodes at the end of the tail
		//and move the tail
		for (auto ptr = head; ptr != odd_chain_end;)
		{
			tail->next = ptr->next;
			ptr->next = ptr->next->next;
			ptr = ptr->next;
			tail = tail->next;
			tail->next = nullptr;
		}

		
		if(last_even_node)
		{
			tail->next = last_even_node;
		}

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
