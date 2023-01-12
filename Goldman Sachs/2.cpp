//593. Valid Square
class Solution {
public:
    double distance(vector<int>& p1, vector<int>& p2){
        return sqrt((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]));
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<double> d(6);
        d[0] = distance(p1,p2);
        d[1] = distance(p1,p3);
        d[2] = distance(p1,p4);
        d[3] = distance(p2,p3);
        d[4] = distance(p3,p4);
        d[5] = distance(p2,p4);
        sort(d.begin(),d.end());

        if(d[0]!=0 && d[0]==d[1] && d[2]==d[3] && d[0]==d[2] && d[4]==d[5]
    ) return true;
        else return false;


    }
};