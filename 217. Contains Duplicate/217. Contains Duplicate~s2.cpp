#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_set>

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
// tc : O(1)
// sc : O(n)
// where n = nums.size()
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set nums_set(begin(nums), end(nums));
        return nums_set.size() < nums.size();
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
