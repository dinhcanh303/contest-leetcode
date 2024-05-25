class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        int m = queries.size();
        vector<int> target;
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(nums[i] == x){
                target.push_back(i);
            }
        }
        for(int query : queries){
            if(query - 1 < target.size()){
                res.push_back(target[query - 1]);
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
};