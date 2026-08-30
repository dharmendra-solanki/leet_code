class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int it: nums){
            if(st.find(it) != st.end()){
                return true;
            }
            st.insert(it);
        }
        return false;
    }
};