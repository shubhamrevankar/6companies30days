// 216. Combination Sum III
class Solution {
public:

    void fun(int i,int target,vector<vector<int>> &res,vector<int> &temp,int n,int k){
        if(target<0 || temp.size()>k) return;
        if(target==0 && temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int j=i;j<n;j++){
            temp.push_back(j+1);
            fun(j+1,target-(j+1),res,temp,n,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> res;
        vector<int> temp;
        fun(0,n,res,temp,9,k);
        return res;
    }
};