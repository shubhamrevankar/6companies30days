class Solution {
public:
    int maxmoney=-INT_MAX;

    void dfs(vector<vector<int>> &adj,int a,int i,int pa,vector<int> &amount,int money,vector<bool> &visited,vector<int> &path){
        
        if(!visited[a]){
            money += amount[a];
        }
        else{
            if(i<path.size() && a==path[i])
                money += amount[a]/2;
        }

        if(adj[a].size()==1 && a!=0){
            maxmoney = max(maxmoney,money);
            return;
        }
        if(i+1<path.size())
            visited[path[i+1]]=true;
        for(auto x:adj[a]){
            if(x!=pa){
                dfs(adj,x,i+1,a,amount,money,visited,path);
            }
        }
        if(i+1<path.size())
            visited[path[i+1]]=false;
    }

    void path_of_b(int b,vector<vector<int>> &adj,vector<int> &temp,int p,vector<int> &path){
        if(b==0){
            if(path.size()==0){
                path = temp;
            }
            else if(path.size()>temp.size()){
                path = temp;
            }
        }
        else{
            for(auto x:adj[b]){
                if(x!=p){
                    temp.push_back(x);
                    path_of_b(x,adj,temp,b,path);
                    temp.pop_back();
                }
            }
        }
    }


    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

        int n = amount.size();
        
        if(n==2){
            return amount[0];
        }
        vector<vector<int>> adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> path,temp;
        temp.push_back(bob);
        path_of_b(bob,adj,temp,-1,path);
        vector<bool> visited(n,false);
        if(path.size())
            visited[path[0]]=true;
        dfs(adj,0,0,-1,amount,0,visited,path);

        return maxmoney;
    }
};