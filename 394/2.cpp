class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> a(150, -1);
        vector<int> b(150,-1);
        for(int i = 0 ; i <= n; i++){
            if(word[i] >= 65 && word[i] <= 90){
                if(a[word[i]] == -1) a[word[i]] = i;
            }else b[word[i]] = i;
        }
        int cnt = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i]== -1 || b[i+32] == -1) continue;
            if(b[i+32] < a[i]) cnt++;
        }
        return cnt;
    }
};