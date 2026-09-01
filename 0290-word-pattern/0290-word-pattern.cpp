class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
       
        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> mpST;
        unordered_map<string, char> mpTS;

        for(int i = 0; i < pattern.size(); i++) {

            char a = pattern[i];
            string b = words[i];

            if(mpST.count(a) && mpST[a] != b)
                return false;

            if(mpTS.count(b) && mpTS[b] != a)
                return false;

            mpST[a] = b;
            mpTS[b] = a;
        }

        return true;
    }
};