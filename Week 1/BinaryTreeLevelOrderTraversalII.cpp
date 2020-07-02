/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
eturn its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
int findDepth(TreeNode* root){
  if(root==NULL) return 0;
  return max(findDepth(root->left),findDepth(root->right))+1;
}
void getElements(vector<vector<int>> &res, int depth, TreeNode* root){
  if(root==NULL) return;
  res[depth-1].push_back(root->val);
  getElements(res,depth-1,root->left);
  getElements(res,depth-1,root->right);
}
vector<vector<int>> levelOrderBottom(TreeNode* root) {
  if(root==NULL) return {};
  int depth=findDepth(root);
  vector<vector<int>> res(depth);
  getElements(res,depth,root);
  return res;
}
};
