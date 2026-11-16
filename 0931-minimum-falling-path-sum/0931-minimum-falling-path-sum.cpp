class Solution {
public:
    int solve(int i , int j , vector<vector<int>> &arr , vector<vector<int>> &dp){
        int n = arr.size();
        int m = arr[0].size();

        if(j < 0 || j >= m) return 1e9;
        if(i == 0) return arr[0][j];

        if(dp[i][j] != INT_MAX) return dp[i][j];


        int up = arr[i][j] + solve(i-1 , j , arr , dp);
        int ld = arr[i][j] + solve(i-1 , j-1 ,arr , dp);
        int rd = arr[i][j] + solve(i - 1 , j + 1 ,arr,dp);

        return dp[i][j] = min(up , min(ld , rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n , vector<int>(m , INT_MAX));

        int mini = INT_MAX;

        for(int j=0; j<m; j++){
            mini = min(mini , solve(n-1 , j , matrix , dp));
        }
        return mini;
    }
};