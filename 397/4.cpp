class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        int size = nums.size();
        vector<int> p(size);
        iota(p.begin(),p.end(),0);
        int min_ = numeric_limits<int>::max();
        vector<int> minPer;
        do {
            int score = 0; 
            for(int i = 0 ; i < size ; ++i){
                score += abs(p[i] - nums[p[(i+1) % size]]);
            }
            if(score < min_){
                min_ = score;
                minPer = p;
            }
        }while(next_permutation(p.begin(),p.end()));
        return minPer;
    }
};