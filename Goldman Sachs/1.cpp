// 149. Max Points on a Line
class Solution {
public:
    double slope(vector<int>& p1, vector<int>& p2){
        if(p2[0]==p1[0]) return INT_MAX;
        return ((1.0*(p2[1]-p1[1]))/(p2[0]-p1[0]));
    }
    int hst_fre(unordered_map<double,int> m){
        int mx=0;
        for(auto x:m){
            mx=max(mx,x.second);
        }
        return mx;
    }
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double,int> m;
        int n = points.size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                m[slope(points[i],points[j])]++;
            }
            res = max(res,hst_fre(m));
            m.clear();
        }
        return res+1;
    }
};