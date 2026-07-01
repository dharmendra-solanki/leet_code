class Solution {
public:
    string majorityFrequencyGroup(string s) {

    unordered_map<char,int> freq;

    for(char ch : s){
        freq[ch]++;
    }

    unordered_map<int,string> groups;

    for(auto it : freq){
        groups[it.second] += it.first;
    }

    string ans = "";
    int maxSize = 0;
    int bestFreq = 0;

    for(auto it : groups){

        int frequency = it.first;
        string chars = it.second;

        if(chars.size() > maxSize){
            maxSize = chars.size();
            bestFreq = frequency;
            ans = chars;
        }
        else if(chars.size() == maxSize && frequency > bestFreq){
            bestFreq = frequency;
            ans = chars;
        }
    }

    return ans;
}
};