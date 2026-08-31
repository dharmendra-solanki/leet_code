class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int el;
        for(int i=1; i<=n; i++){
            sum += i;
        }
        for(int i=0; i<n; i++){
            sum = sum - nums[i];
        }
        return sum;
    }
};