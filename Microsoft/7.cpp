class Solution {
public:

    bool dfs(vector<vector<int>> &adj,int i,vector<bool> &visited,vector<bool> &calls){
        calls[i]=true;

        for(auto x:adj[i]){
            if(!visited[x]){
                visited[x]=true;
                if(dfs(adj,x,visited,calls)){
                    return true;
                }
            }
            else if(calls[x]){
                return true;
            }
        }
        calls[i]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> calls(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                visited[i]=true;
                if(dfs(adj,i,visited,calls)){
                    return false;
                }
            }
        }
        return true;
    }
};