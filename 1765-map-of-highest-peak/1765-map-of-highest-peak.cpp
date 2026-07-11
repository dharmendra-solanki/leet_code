class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> ans(n , vector<int>(m,0));
        vector<vector<int>> vis(n , vector<int>(m,0));
        queue<pair<pair<int,int>, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({{i,j}, 0});
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int drow[] = {+1 ,0 ,-1, 0};
        int dcol[] = {0 , -1, 0, +1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            ans[row][col] = step;

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n  && ncol >= 0 && ncol < m && 
                vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow , ncol}, step+1});
                }
            }
        }
        return ans;
    }
};