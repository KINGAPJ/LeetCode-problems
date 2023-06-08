class Solution {
public:
    string getPermutation(int n, int k) {
        int facs[n+1];
        facs[0] = 1;
        for(int i = 1; i <= n; i++){
            facs[i] = facs[i-1] * i;
        }
        k--;
        string nums = "", ans = "";
        for(int i = 1; i <= n; i++)
            nums.push_back(i+'0');
        int i = n-1;
        while(i){
            int dig = k/facs[i];
            ans.push_back(nums[dig]);
            nums.erase(dig, 1);
            k -= dig*facs[i--];
        }
        ans.push_back(nums[0]);
        return ans;
    }
};