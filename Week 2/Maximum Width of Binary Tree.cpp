/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. 
The binary tree has the same structure as a full binary tree, but some nodes are null.
The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, 
where the null nodes between the end-nodes are also counted into the length calculation.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void dfs(TreeNode* root, int &res,int prev, int level, vector<int> &lval){
  if(root==NULL) return;
  root->val=prev;
  if(level==lval.size()) lval.push_back(prev);
  res=max((int)prev-lval[level]+1,res);
  dfs(root->left,res,(long)2*root->val,level+1,lval);
  dfs(root->right,res,(long)2*root->val+1,level+1,lval);
}
int widthOfBinaryTree(TreeNode* root) {
  if(root==NULL) return 0;
  int res=0;
  vector<int> lval;
  dfs(root,res,1,0,lval);
  return res;
}
};
