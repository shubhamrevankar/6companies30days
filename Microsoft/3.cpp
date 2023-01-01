// 299. Bulls and Cows
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0,cows=0;
        int count[10] = {0};
        int n=secret.length();
        for(int i=0;i<n;i++) {
            if(guess[i]!=secret[i])
            count[secret[i]-'0']++;
        }
        for(int i=0;i<n;i++){
            if(guess[i]==secret[i]){
                bulls++;
            }
            else if(count[guess[i]-'0']>0){
                cows++;
                count[guess[i]-'0']--;
            }
        }
        string res = to_string(bulls)+"A"+to_string(cows)+"B";
        return res;
    }
};