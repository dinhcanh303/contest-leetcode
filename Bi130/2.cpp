class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            points[i][0] = abs(points[i][0]);
            points[i][1] = abs(points[i][1]);
        }
        int l = 0 , r = 1e9; //points[i][1] <= 10^9
        int res = 0;
        while(l <= r){
            int mid = (l + r) /2;
            map<char,int> mapCnt;
            bool check = true;
            for(int i = 0; i < n;i++){
                if(points[i][0] <= mid && points[i][1] <= mid){
                    mapCnt[s[i]]++;
                }
            }
            for(auto it : mapCnt){
                if(it.second > 1){
                    check = false;
                    break;
                }
            }
            if(check){
                res = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        for(int i = 0; i < n; i++){
            if(points[i][0] <= res && points[i][1] <= res){
                cnt++;
            }
        }
        return cnt;
        
    }
};