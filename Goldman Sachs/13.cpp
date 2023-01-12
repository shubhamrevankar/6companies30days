//1878. Get Biggest Three Rhombus Sums in a Grid
class Solution {
public:
    int forone(vector<vector<int>>& grid,int x,int y,int romsize,int m,int n){
        if(y+1<romsize || n-y<romsize || (x+2*romsize-2)>=m){
            return -1;
        }
        int sum=0;
        int u=x,d=x+2*romsize-2;
        for(int i=y;i<=y+romsize-1;i++){
            if(u==d)
                sum += grid[u++][i];
            else
                sum += grid[u++][i] + grid[d--][i];
        }
        u=x+1;d=x+2*romsize-3;
        for(int i=y-1;i>=y-romsize+1;i--){
            if(u==d)
                sum += grid[u++][i];
            else
                sum += grid[u++][i] + grid[d--][i];
        }
        return sum;
    }
// int forone(vector<vector<int>>& grid,int x,int y,int romsize,int m,int n)
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(INT_MIN);pq.push(INT_MIN);pq.push(INT_MIN);

        int maxrom = (min(m,n)+1)/2;

        set<int> s;set<int>::iterator it;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r=1,t;
                while((t=forone(grid,i,j,r++,m,n))!=-1){
                    s.insert(t);
                    if(s.size()>3){
                        it=s.begin();
                        s.erase (*it);
                    }
                }
            }
        }
        vector<int> res;
        
        for(auto x:s){
            res.push_back(x);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};