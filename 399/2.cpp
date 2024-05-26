class Solution {
public:
    string compressedString(string word) {
        string res = "";
        int size = word.size();
        int idx = 0;
        while(idx < size){
            char cur = word[idx];
            int cnt = 0;
            while(idx < size && word[idx] == cur && cnt < 9){
                ++cnt;
                ++idx;
            }
            res += to_string(cnt) + cur;
        }
        return res;
    }
};