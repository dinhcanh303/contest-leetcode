class Solution {
public:
    int dp[1005];
    
    int findSubStr(int index, string &newStr){
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int f[26] = {0};
        int minSubStr = 5005;
        for(int i = index ; i >= 0; i--){
            f[newStr[i]-'a'] += 1;
            int max_ = -1 , min_ = 5005;
            for(int j = 0; j < 26;j++){
                if(f[j]){
                    min_ = min(min_,f[j]);
                    max_ = max(max_,f[j]);
                }
            }
            if(min_ == max_) minSubStr = min(minSubStr,1 + findSubStr(i-1,newStr));
        }
        return dp[index] = minSubStr;
    }
    int minimumSubstringsInPartition(string s) {
        memset(dp,-1,sizeof dp);
        return findSubStr(s.size() - 1, s);
    }
};