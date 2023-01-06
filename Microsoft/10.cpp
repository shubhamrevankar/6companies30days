class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return 0;
        if(n==2){
            if(nums[0]<=nums[1]) return 0;
            else return 2;
        }

        bool f1=false;int minleft=INT_MAX;
        bool f2=false;int maxright=INT_MIN;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i] && !f1) f1=true;
            if(f1) minleft = min(minleft,nums[i]);
        }
        for(int j=n-2;j>=0;j--){
            if(nums[j]>nums[j+1] && !f2) f2=true;
            if(f2) maxright = max(maxright,nums[j]);
        }
        if(!f1) return 0;
        int i=0,j=n-1;f1=f2=false;
        for(int k=0;k<n;k++){
            if(!f1){
                if(nums[k]>minleft){
                    i=k;
                    f1=true;
                }
            }
        }
        for(int k=n-1;k>=0;k--){
            if(!f2){
                if(nums[k]<maxright){
                    j=k;
                    f2=true;
                }
            }
        }
            

        return j-i+1;
    }
};