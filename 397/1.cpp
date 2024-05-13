class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int> sIndex,tIndex;
        for (int i = 0; i < s.length(); ++i) {
        sIndex[s[i]] = i;
        tIndex[t[i]] = i;
        }
        int difference = 0;
        for (int i = 0; i < s.length(); ++i) {
            difference += abs(sIndex[s[i]] - tIndex[s[i]]);
        }
        return difference;
    }
};