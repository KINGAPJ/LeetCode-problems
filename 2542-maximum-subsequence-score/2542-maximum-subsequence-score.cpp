#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<ll, ll>> nums;
        ll n = nums1.size();
        for(ll i = 0; i < n; i++)
            nums.push_back({nums2[i], nums1[i]});
        sort(nums.begin(), nums.end(), greater<pair<ll, ll>>());
        ll ans = 0;
        ll curr_sum = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(ll i = 0; i < k; i++){
            pq.push(nums[i].second);
            curr_sum += nums[i].second;
        }
        ans = curr_sum * nums[k-1].first;
        for(ll i = k; i < n; i++){
            auto u = pq.top();
            curr_sum += (nums[i].second - u);
            pq.pop();
            pq.push(nums[i].second);
            ans = max(ans, curr_sum * nums[i].first);
            // if((curr_sum - u + nums[i].second) * nums[i].first > ans){
            //     ans = (curr_sum - u + nums[i].second) * nums[i].first;
            //     curr_sum += (nums[i].second - u);
            //     pq.pop();
            //     pq.push(nums[i].second);
            // } 
        }
        return ans;
    }
};