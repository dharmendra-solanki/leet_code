class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, last = -1;
        int s = 0;
        int e = n - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                first = mid;
                e = mid - 1;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        s = 0;
        e = n - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                last = mid;
                s = mid + 1;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return {first , last};
    }
};