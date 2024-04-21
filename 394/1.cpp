class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<int>s1;
        set<int>s2;
        for(auto i : word){
            if(i>='a' && i <= 'z') s1.insert(i-'a');
            else s2.insert(i-'A');
        }
        int cnt = 0;
        for(auto i : s1){
            if(s2.find(i) !=s2.end()) cnt++;
        }
        return cnt;
    }
};