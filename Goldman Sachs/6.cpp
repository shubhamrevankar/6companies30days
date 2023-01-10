//2260. Minimum Consecutive Cards to Pick Up
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int res = INT_MAX;
        unordered_map <int,int> m;
        int  n= cards.size();
        for(int i=0;i<n;i++){
            if(m.find(cards[i]) == m.end()){
                m[cards[i]] = i;
            }
            else{
                res = min(res,i-m[cards[i]]+1);
                m[cards[i]] = i;
            }
        }
        if(res==INT_MAX) return -1;
        else return res;
    }
};