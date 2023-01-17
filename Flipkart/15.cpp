// 337. House Robber III
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
    unordered_map<TreeNode*,int> m;
    int rob(TreeNode* root) {
        if(root==NULL) return 0; 
        if(root->left==NULL && root->right==NULL){
            m[root]=root->val;
            return root->val;
        }
        int children = (m[root->left]=rob(root->left)) + (m[root->right]=rob(root->right));
        int subchildren = 0;
        if(root->left!=NULL){
            subchildren += m[root->left->left]+m[root->left->right];
        }
        if(root->right!=NULL){
            subchildren += m[root->right->left]+m[root->right->right];
        }
        
        return max(root->val+subchildren,children);
    }
};