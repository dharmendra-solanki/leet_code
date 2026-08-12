class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size() , i = 0 , j = 0;
        unordered_map<int,int> mpp;
        int cnt = 0;

        while(j < n){
            mpp[nums[j]]++;
            while(mpp[nums[j]] > k){
                mpp[nums[i]]--;
                i++;
            }
            cnt = max(cnt , j - i + 1);
            j++;
        }
        return cnt;
    }
};