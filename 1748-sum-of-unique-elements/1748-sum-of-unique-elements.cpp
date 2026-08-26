class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        int freq[101] = {0};
        int sum = 0;

        for(int num : nums){
            freq[num]++;
        }
        for(int i=0; i<n; i++){
            if(freq[nums[i]] == 1){
                sum = sum + nums[i];
            }
        }
        return sum;
    }
};