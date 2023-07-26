class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo = 1, hi = 1e7+1;
        int ans = hi;
        while(lo <= hi){
            int spd = lo + (hi - lo)/2;
            double time = 0;
            for(int i = 0; i < dist.size()-1; i++)
                time += (dist[i]+spd-1)/spd;
            time += ((double)dist.back())/spd;
            if(time <= hour){
                hi = spd - 1;
                ans = min(ans, spd);
            }else
                lo = spd + 1;
        }
        return ans == 1e7+1 ? -1 : ans;
    }
};