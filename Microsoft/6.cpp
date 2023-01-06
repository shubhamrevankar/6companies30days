class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<int,int> m;
        int x,y,a,b;
        for(auto r:rectangles){
            x=r[0];y=r[1];a=r[2];b=r[3];
            m[20000*x+y]++;
            m[20000*a+b]++;
            m[20000*x+b]--;
            m[20000*a+y]--;
        }
        int corners=0;
        for(auto mp:m){
            if(mp.second!=0){
                if(abs(mp.second)==1){
                    corners++;
                }
                else{
                    return false;
                }
            }
        }
        return corners==4;
    }
};