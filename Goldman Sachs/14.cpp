//1814. Count Nice Pairs in an Array
#define MOD 1000000007
class Solution {
public:

    int rev(int n){
        int reversed_number = 0, remainder;
        while(n != 0) {
            remainder = n % 10;
            reversed_number = reversed_number * 10 + remainder;
            n /= 10;
        }
        return reversed_number;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        int res=0;
        for(int i=0;i<n;i++) res = (res + m[nums[i] - rev(nums[i])]++)%MOD;
        return res;
    }
};