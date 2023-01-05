class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int res=0;
        int n = s.length();
        int count[3] = {0};
        int l=0,h=0;
        count[s[0]-'a']++;
        while(h<n){
            while(h<n-1 && !(count[0]>0 && count[1]>0 && count[2]>0)){
                count[s[++h]-'a']++;
            }
            if(!(count[0]>0 && count[1]>0 && count[2]>0)){
                break;
            }
            int left=0;
            while(count[0]>0 && count[1]>0 && count[2]>0){
                count[s[l++]-'a']--;left++;
            }
            res += (left*(n-h));
        }
        return res;
    }
};