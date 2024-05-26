class Solution {
public:
    const int MOD = 1e9+7;
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        vector<long long> a(size);
        vector<long long> b(size);

        a[0] = max(0LL, (long long)nums[0]);
        b[0] = 0;
        for(int i = 1 ; i < size; i++){
            a[i] = max(0LL,(long long)nums[i] + b[i-1]);
            b[i] = max(a[i-1],b[i-1]);
        }
        long long maxSum = max(a[size-1],b[size-1]);
        long long totalSum = 0;
        for(auto q : queries){
            int p = q[0];
            int val = q[1];
            nums[p] = val;
            if(p == 0){
                a[0] = max(0LL,(long long)nums[0]);
                b[0] = 0;
            }
            for(int i = max(1,p); i < size; i++){
                if(i == p) a[i] = max(0LL,(long long)nums[i] + (i > 0 ? b[i-1] : 0));
                else a[i] = max(0LL, (long long)nums[i] + b[i-1]);
                b[i] = max(a[i-1],b[i-1]);
            }
            maxSum = max(a[size-1],b[size-1]);
            totalSum = (totalSum + maxSum) % MOD;
        }
        return static_cast<int>(totalSum);
    }
};