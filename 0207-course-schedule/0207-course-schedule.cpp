class Solution {
private:
    bool dfs(int node , vector<int> &vis , vector<int> &pathVis 
    , vector<vector<int>> &adj){
        
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            // when the node is node visited
            if(!vis[it]){
                if(dfs(it , vis, pathVis, adj) == true) return true;
            }
            // if the node has been previously visted 
            /// but it has to be vistend on same path
            else if(pathVis[it]){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(auto &edge : prerequisites){
        
            int u = edge[0];
            int v = edge[1];
        
            adj[u].push_back(v);
        }

        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i , vis, pathVis, adj)) return false;
            }
        }
        return true;
    }
};