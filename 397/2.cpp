class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int max_ = INT_MIN;
        for(int i = n -1; i >= n - k; --i){
            int cur = 0;
            for(int j = i ; j >= 0; j -=k){
                cur += energy[j];
                max_ = max(max_,cur);
            }
        }
        return max_;
    }
};