// 2265. Count Nodes Equal to Average of Subtree
class Solution {
public:
    int res=0;
    pair<int,int> inorder (TreeNode* root){
        if(root==NULL) return {0,0};
        pair<int,int> left = inorder(root->left);
        pair<int,int> right = inorder(root->right);
        pair<int,int> ret = {left.first+right.first+root->val,left.second+right.second+1};
        if(ret.first/ret.second == root->val) res++;
        return ret;
    }
    int averageOfSubtree(TreeNode* root) {
        inorder(root);
        return res;
    }
};