class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int k ;
        reverse(nums.begin() , nums.end());
        reverse(nums.begin() , nums.begin() + k);
        reverse(nums.begin()+k , nums.end());

        for(int i=0; i<n; i++){
            if(nums[i] == target) return true;
        }
        return false;
    }
};