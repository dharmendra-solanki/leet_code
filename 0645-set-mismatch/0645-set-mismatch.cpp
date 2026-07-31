class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n+1,0);
        int duplicate = -1;
        int missing = -1;
        for(int i=0; i<n; i++){
            ans[nums[i]]++;
        }
        for(int i=1; i<=n; i++){
            if(ans[i] == 2) duplicate = i;
            if(ans[i] == 0) missing = i;
        }
        
        return {duplicate , missing};
    }
};