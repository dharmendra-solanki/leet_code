class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            int targetCnt = 0;
            int otherCnt = 0;
            for(int j=i; j<n; j++){
                if(nums[j] == target){
                    targetCnt++;
                }
                else{
                    otherCnt++;
                }
                if(targetCnt > otherCnt) ans++;
            }
        }
        return ans;
    }
};