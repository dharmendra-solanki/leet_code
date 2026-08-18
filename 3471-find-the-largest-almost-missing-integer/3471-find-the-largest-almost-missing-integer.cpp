class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int freq[51] = {0};

        for(auto num : nums){
            freq[num]++;
        }
        int res = -1;
        for(int i=0; i<n; i++){
            if(k == n) res = max(res , nums[i]);
            else if(freq[nums[i]] == 1){
                if(k == 1) res = max(res , nums[i]);
                else if(!i || i == n - 1) res = max(res, nums[i]);
            }
        }
        return res;
    }
};