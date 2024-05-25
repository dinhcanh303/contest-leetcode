class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int a[51] = {0};
        for(int num : nums){
            a[num]++;
        }
        int res = 0;
        for(int i = 0; i <= 50; i++){
            if(a[i] == 2){
                res ^= i;
            }
        }
        return res;
    }
};