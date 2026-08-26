class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string res = "";
        int oneCnt = 0;
        int minLen = INT_MAX;
        int left = 0;

        for(int right=0; right<n; right++){
            if(s[right] == '1'){
                oneCnt++;
            }
            while(oneCnt == k){
                while(s[left] == '0') left++;
                int currentLen = right - left + 1;
                string currStr = s.substr(left , currentLen);

                if(currentLen < minLen){
                    minLen = currentLen;
                    res = currStr;
                }
                if(minLen == currentLen){
                   res = min(res, currStr);
                }
                if(s[left] == '1'){
                    oneCnt--;
                }
                left++;
            }
        }
        return res;
    }
};