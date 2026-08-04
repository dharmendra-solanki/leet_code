class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        vector<int> ans;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
            mini = min(mini , nums[i]);
            maxi = max(maxi , nums[i]);
        }
        for(int i=mini; i<maxi; i++){
            if(st.count(i) == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};