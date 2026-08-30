class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char,char> mpST;
        unordered_map<char,char> mpTS;

        for(int i=0; i<s.size(); i++){
            char a = s[i];
            char b = t[i];

            // s -> t mapping check
            if(mpST.count(a) && mpST[a] != b)
                return false;

            // t -> s mapping check
            if(mpTS.count(b) && mpTS[b] != a)
                return false;

            mpST[a] = b;
            mpTS[b] = a;
        }
        return true;
    }
};