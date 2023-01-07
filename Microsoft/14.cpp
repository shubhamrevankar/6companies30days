class Solution {
public:
int gcd(int a, int b){ if (a == 0) return b;return gcd(b % a, a);}

int findGCD(vector<int> &arr, int n)
{
  int result = arr[0];
  for (int i = 1; i < n; i++)
  {
    result = gcd(arr[i], result);
 
    if(result == 1)
    {
    return 1;
    }
  }
  return result;
}

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd = findGCD(numsDivide,numsDivide.size());

        int n=nums.size();
        bool flag=false;
        int count=0;
        int ele=gcd;
        for(int i=0;i<n;i++){
            if(gcd%nums[i]==0 && nums[i]<=ele){
                ele=nums[i];
                flag=true;
            }
        }
        if(!flag) return -1;
        for(int i=0;i<n;i++){
            if(nums[i]<ele) count++;
        }
        return count;
        
    }
};