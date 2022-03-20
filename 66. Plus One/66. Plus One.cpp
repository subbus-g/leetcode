// https://leetcode.com/problems/plus-one/
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
//time-compelexity : O(digits.size())
//space-complexity : O(1)
class Solution
{
public:
   vector<int> plusOne(vector<int> &digits)
   {
      //traverse from LSD to MSD
      for (auto it = digits.rbegin(); it != digits.rend(); it++)
      {
         //if the digit is not 9 then increment it and return the vector immediately
         if (*it != 9)
         {
            (*it)++;
            return digits;
         }
         //if the digit is 9 , change it to 0
         //and the loop continues until non-9 digit appear or all the digits are over
         *it = 0;
      }
      //since all 9's, we have carry 1, so insert it at front as MSD
      digits.insert(digits.begin(), 1);
      return digits;
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
      vector<int> digits(n);
      cin >> digits;
      cout << sol.plusOne(digits);
   }

   return 0;
}
