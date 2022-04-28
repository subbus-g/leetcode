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
   for_each(begin(v), end(v) - 1,[&](const auto& element){
      out << element << ",";
   } );
   out << v.back() << "]" << endl;

   return out;
}

class Solution
{
public:
   vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
   {
      //create two sets from the values of given two input vectors
      unordered_set<int> set1(begin(nums1), end(nums1));
      unordered_set<int> set2(begin(nums2), end(nums2));

      //create result vector to store the unique common elements
      vector<int> result;

      //for each element in set 1
      for (auto x : set1)
      {
         //if it is present on set2
         if (set2.find(x) != set2.end())
         {
            //store it in result
            //since set1 is set,no duplicates will be stored in result
            result.push_back(x);
         }
      }

      return result;
   }
   //TC : Θ(n + m) in average case
   //SC : Θ(n + m) in worst case
   //where n = size(num1), m=size(nums2)

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
