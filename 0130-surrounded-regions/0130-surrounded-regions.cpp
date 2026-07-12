class Solution {
private:
    void dfs(int row , int col ,vector<vector<char>>& board, vector<vector<int>>& vis , 
    int drow[] , int dcol[]){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow <n && ncol >=0 && ncol <m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow , ncol , board , vis , drow , dcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));

        int drow[] = {-1 ,0 ,1 ,0};
        int dcol[] = {0 , 1, 0, -1};

        // traverse a first row and last row
        for(int j=0; j<m; j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0 , j ,board , vis, drow, dcol);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1 , j ,board , vis, drow, dcol);
            }
        }

        // traverse a first col and last col
        for(int i=0; i<n; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, board , vis, drow, dcol);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i , m-1 ,board , vis, drow, dcol);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};