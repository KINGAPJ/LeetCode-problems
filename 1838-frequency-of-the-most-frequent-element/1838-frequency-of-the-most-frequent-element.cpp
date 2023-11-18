class Solution {
public:
    bool can(vector<int>& nums, int len, int k)
    { 
      long long sum = 0;
      for (int i = 0; i < len - 1; i++)
      {
        sum += nums[i]; 
      }
      for (int i = 0, j = len-1; j < nums.size(); j++, i++)
      {
        sum += nums[j]; 
        long long need = 1LL * nums[j] * len; 
        if (need - sum <= k)return 1; 
        sum -= nums[i];
      }
      return 0;
    }
    int maxFrequency(vector<int>& nums, int k) {
      int l = 1, r = nums.size(), m, ans = 0;
      sort(nums.begin(), nums.end());
      while(l <= r)
      {
        m = (l+r) >> 1;
        if(can(nums, m, k))
          ans = m, l = m+1; 
        else 
          r = m-1;
      }
      return ans;
    }
    // int maxFrequency(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     int lo = 1, hi = n, mid;
    //     while(lo < hi){
    //         bool yes = true;
    //         mid = lo + (hi - lo + 1)/2;
    //         cout<<"lo: "<<lo<<" mi: "<<mid<<" hi: "<<hi<<"\n";
    //         long long int window = accumulate(nums.begin(), nums.begin() + mid, 0LL);
    //         cout<<"window: "<<window<<" mi * nums[i]: "<<mid*nums[mid-1]<<" diff: "<<(mid*nums[mid-1] - window)<<'\n';
    //         if(mid * nums[mid-1] - window <= k){
    //             lo = mid;
    //             continue;
    //         }
    //         for(int i = mid; i < n; i++){
    //             window += (nums[i] - nums[i - mid]);
    //             cout<<"i: "<<i<<" window: "<<window<<" mi * nums[i]: "<<mid*nums[i]<<" diff: "<<(mid*nums[i] - window)<<'\n';
    //             if(mid * nums[i] - window <= k){
    //                 lo = mid;
    //                 yes = false;
    //                 break;
    //             }
    //         }
    //         if(yes)
    //             hi = mid - 1;
    //     }
    //     cout<<'\n';
    //     return lo;
    // }
};