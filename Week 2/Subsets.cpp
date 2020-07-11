/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
void backtrack(vector<vector<int>> &res, vector<int> &temp, int pos, int n, vector<int> &nums){
  res.push_back(temp);
  for(int i=pos;i<n;i++){
    temp.push_back(nums[i]);
    backtrack(res,temp,i+1,n,nums);
    temp.pop_back();
  }
}
vector<vector<int>> subsets(vector<int>& nums) {
  int n=nums.size();
  if(n==0) return {};
  vector<vector<int>> res;
  vector<int> temp;
  backtrack(res,temp,0,n,nums);
  return res;
}
};
