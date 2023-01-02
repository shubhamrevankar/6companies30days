//368. Largest Divisible Subset
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> idx(n,-1);
        vector<int> len(n,1);
        int start = 0;
        for(int i=n-1;i>=0;i--){
            int next=-1;
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    if(next==-1) next=j;
                    else{
                        if(len[next]<len[j]) next=j;
                    }
                }
            }
            if(next!=-1){
                idx[i]=next;
                len[i]=len[next]+1;
                if(len[start]<len[i]) start = i;
            }
        }
        vector<int> res;
        int i=start;
        while(i!=-1){
            res.push_back(nums[i]);
            i = idx[i];
        }
        return res;
    }
};