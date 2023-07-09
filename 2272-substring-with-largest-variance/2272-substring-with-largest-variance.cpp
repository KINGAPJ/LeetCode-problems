class Solution {
    int kadane(vector<int>& arr){
        int n = arr.size();
        int rem_minus1 = 0;
        for(int i = 0; i < n; i++)
            rem_minus1 += arr[i] == -1;
        int res = 0, curr = 0;
        bool ok = false;
        for(int i = 0; i < n; i++){
            curr += arr[i];
            if(arr[i] == -1){
                ok = true;
                rem_minus1--;
            }
            if(curr < 0 && rem_minus1 >= 1){
                curr = 0;
                ok = false;   
            }
            if(ok){
                res = max(res, curr);
            }
        }
        return res;
    }
public:
    int largestVariance(string s) {
        int n = s.size(), ans = 0;
        for(int i = 'a'; i <= 'z'; i++){
            for(int j = 'a'; j <= 'z'; j++){
                if(i == j)
                    continue;
                vector<int> arr(n);
                for(int ind = 0; ind < n; ind++){
                    if(s[ind] == i){
                        arr[ind] = 1;
                    }else if(s[ind] == j){
                        arr[ind] = -1;
                    }
                }
                ans = max(ans, kadane(arr));
                // cout<<((char)i)<<' '<<((char)j)<<' '<<ans<<'\n';
            }
        }
        return ans;
    }
};