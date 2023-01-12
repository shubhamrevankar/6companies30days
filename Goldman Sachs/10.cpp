//2327. Number of People Aware of a Secret
#define MOD 1000000007
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> v(n+1,0);
        v[1]=1;
        int res=0;
        if(forget>=n) res++;
        int sum=0;
        for(int i=delay+1;i<=n;i++){

            if(i-delay>0){
                sum = (sum+v[i-delay])%MOD;
            }
            if(i-forget>0){
                sum = ((sum-v[i-forget])%MOD+MOD)%MOD;
            }
            v[i] = sum;
            if(i>n-forget){
                res = (res+v[i])%MOD;
            }
        }
        return res;
    }
};