class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_area = 0;
        int left = 0;
        int right = n - 1;
        while(left < right){
            int width = right - left;
            max_area = max(max_area, width * min(height[left], height[right]));

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_area;
    }
};