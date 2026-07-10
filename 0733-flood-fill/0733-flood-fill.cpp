class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int oldColor ,int newColor){
        int n = image.size();
        int m = image[0].size();
        image[row][col] = newColor;

        int drow[] = {-1 , 0 , 1 ,0};
        int dcol[] = {0 , 1 , 0 , -1};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               image[nrow][ncol] == oldColor){
                dfs(image , nrow , ncol , oldColor , newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int oldColor = image[sr][sc];
        if(oldColor == color) return image;

        dfs(image , sr , sc, oldColor , color);
        return image;
    }
};