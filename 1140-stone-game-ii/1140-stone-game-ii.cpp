class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(vector<int>& piles, int i, int M) {

        if (i >= n)
            return 0;

        // Remaining stones
        int remaining = suffix[i];

        // Can take all remaining piles
        if (2 * M >= n - i)
            return remaining;

        if (dp[i][M] != -1)
            return dp[i][M];

        int best = 0;

        int taken = 0;

        for (int x = 1; x <= 2 * M; x++) {

            taken += piles[i + x - 1];

            // Opponent gets the best possible score
            int opponent = solve(piles, i + x, max(M, x));

            // Current player's score
            int current = remaining - opponent;

            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        // suffix[i] = sum from i to n-1
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(piles, 0, 1);
    }
};