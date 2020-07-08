/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(),nums.end());
  vector<vector<int>> res;
  int n=nums.size();
  for(int i=0;i<nums.size();i++){
    int l=i+1,r=nums.size()-1;
    while(l<r){
      int sum=nums[i]+nums[l]+nums[r];
      if(sum==0){
        res.push_back({nums[i],nums[l],nums[r]});
        while(l+1<r&&nums[l]==nums[l+1]) l++;
        while(l<r-1&&nums[r]==nums[r-1]) r--;         
        l++;r--;
        //cout<<l<<r<<endl;
      }
      else if(sum>0) r--;
      else l++;
    }
    while(i+1<n&&nums[i]==nums[i+1]) i++;
  }
  return res;
}
};
