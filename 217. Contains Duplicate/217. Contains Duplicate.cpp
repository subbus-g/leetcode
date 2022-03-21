#include <bits/stdc++.h>
using namespace std;

// for cout<<vector
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &element : v)
    {
        in >> element;
    }
    return in;
}
// for cin>>vector
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &element : v)
        out << element << " ";
    out << endl;
    return out;
}
// tc : O(n.logn)
// sc : O(1)
// where n = nums.size()
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        //sort the nums
        sort(begin(nums), end(nums));
        //and check if any two consective elements are equal are not
        for (auto it = begin(nums); it != end(nums) - 1; it++)
        {
            if (*it == *(it + 1))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("0.1-in.txt", "r", stdin);
    freopen("0.3-out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    Solution sol;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        cin >> nums;
        cout << boolalpha << sol.containsDuplicate(nums) << endl;
    }
    return 0;
}
