class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool hasNotZero = false;
        for(int num : nums){
            xr = xr ^ num;
            if(xr != 0) hasNotZero = true;
        }
        if(xr != 0) return n;
        if(hasNotZero) return n-1;
        return 0;
    }
};