class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int num = 0;
        // int ans = 0;
        for(int i=low; i<=high; i++){
            num = num ^ nums[i];
        }
        // while(low <= high){
        //     int mid = low + (high - low)/2;
        //     if(nums[mid] > num){
        //         high = mid - 1;
        //     }
        //     else if(nums[mid] < num){
        //         low = mid + 1;
        //     }
        //     else{
        //         ans = nums[mid];
        //     }
        // }
        return num;
    }
};