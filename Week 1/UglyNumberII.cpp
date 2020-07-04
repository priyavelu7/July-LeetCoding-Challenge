/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
*/
class Solution {
public:
int nthUglyNumber(int n) {    
  if(n==1) return 1;
  int v2=2,v3=3,v5=5,v;
  int i2=0,i3=0,i5=0;
  vector<int> list(n);
  list[0]=1;
  for(int i=1;i<n;i++){
    v=min(min(v2,v3),v5);
    list[i]=v;
    if(v==v2) v2=list[++i2]*2;
    if(v==v3) v3=list[++i3]*3;
    if(v==v5) v5=list[++i5]*5;
  }
  return list[n-1];
}
};
