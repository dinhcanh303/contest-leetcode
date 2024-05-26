class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int> mp;
        long long cnt = 0;
        for(int i : nums2){
            mp[i*k]++;
        }
        for(int num : nums1){
            for(int i = 1; i <= sqrt(num); i++){
                if(num % i == 0){
                    int tmp = num / i;
                    if(mp.count(i)){
                        cnt += mp[i];
                    }
                    if(tmp != i && mp.count(tmp)){
                        cnt += mp[tmp];
                    }
                }
            }
        }
        return cnt;
    }
};