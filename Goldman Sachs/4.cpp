//447. Number of Boomerangs
class Solution {
public:

    double distance(vector<int>&a,vector<int>&b){
        return (sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])));
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<double,int> m;
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res += 2*m[distance(points[i],points[j])]++;
            }
            m.clear();
        }
        
        return res;
    }
};