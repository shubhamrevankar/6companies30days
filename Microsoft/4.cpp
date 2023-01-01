class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum=0,cur=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            cur+=i*nums[i];
        }
        int m=cur;
        for(int i=n-1;i>=0;i--){
            cur -= nums[i]*(n-1);
            cur += (sum - nums[i]);
            m = max(m,cur);
        }
        return m;
    }
};