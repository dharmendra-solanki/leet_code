class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> lenIndex(256 , -1);

        int maxLen = 0;
        int i = 0;
        for(int j=0; j<n; j++){
            if(lenIndex[s[j]] >= i){
                i = lenIndex[s[j]] + 1;
            }
            lenIndex[s[j]] = j;
            maxLen = max(maxLen , j- i+ 1);
        }
        return maxLen;
    }
};