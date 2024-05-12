// Fail
class Solution {
public:
    const int MOD = 1e9+7;
    vector<int> gen(int x){
        vector<int> a;
        int b = 1;
        while(x > 0){
            if(x & 1){
                a.push_back(b);
            }
            x >>= 1;
            b <<= 1;
        }
        return a;
    }
    int cal(vector<int> &big_nums, int fromI , int toI , int modI){
        int product = 1;
        for(int i = fromI; i <= toI && i < big_nums.size(); ++i){
            product = (1ll * product * big_nums[i]) % modI;
        }
        return product;
    }
    vector<int> findProductsOfElements(vector<vector<long long>> &queries) {
        vector<int> big_nums;
        for(int i = 1; i <= 500; ++i){
            vector<int> powerFullArr = gen(i);
            big_nums.insert(big_nums.end(),powerFullArr.begin(),powerFullArr.end());
        }
        vector<int> ans;
        for(auto &q : queries){
            int fromI = q[0];
            int toI = q[1];
            int modI = q[2];
            int res = cal(big_nums,fromI,toI,modI);
            ans.push_back(res);
        }
        return ans;
    }
};