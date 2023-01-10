//172. Factorial Trailing Zeroes
class Solution {
public:
    int trailingZeroes(int n) {
        double lg5 = log(5);
        int res=0;
        while(n!=0){
            while(n%5!=0)n--;
            n /= 5;
            res+=n;
        }
        return res;
    }
};