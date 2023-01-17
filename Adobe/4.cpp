//481. Magical String
class Solution {
public:
    int magicalString(int n) {

        if(n==1 || n==2 || n==3) return 1;

        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(2);
        int i=2,p=1;
        int ones=1;
        while(i<n){
            if(v[i++]==1){
                v.push_back(p);
                ones++;
            }
            else{
                v.push_back(p);
                v.push_back(p);
            }
            p = p==1?2:1;
        }
        
        return ones;
    }
};