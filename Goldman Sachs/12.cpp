//1305. All Elements in Two Binary Search Trees
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &v){

        if(root == NULL) return;

        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        vector<int> res;
        int n1=v1.size(),n2=v2.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(v1[i]<=v2[j]) res.push_back(v1[i++]);
            else res.push_back(v2[j++]);
        }
        while(i<n1){
            res.push_back(v1[i++]);
        }
        while(j<n2){
            res.push_back(v2[j++]);
        }
        return res;
    }
};