#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int el1 = 0, el2 = 0;
    int cnt1 = 0, cnt2 = 0, n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
      if (cnt1 == 0 && nums[i] != el2)
      {
        cnt1 = 1;
        el1 = nums[i];
      }
      else if (cnt2 == 0 && nums[i] != el1)
      {
        cnt2 = 1;
        el2 = nums[i];
      }

      else if (nums[i] == el1)
      {
        cnt1++;
      }
      else if (nums[i] == el2)
      {
        cnt2++;
      }
      else
      {
        cnt1--;
        cnt2--;
      }
    }
    cnt1 = 0, cnt2 = 0;
    for (int &i : nums)
    {
      if (i == el1)
      {
        cnt1++;
      }
      else if (i == el2)
      {
        cnt2++;
      }
    }

    if (cnt1 > n / 3)
    {
      ans.push_back(el1);
    }
    if (cnt2 > n / 3)
    {
      ans.push_back(el2);
    }

    return ans;
  }
};