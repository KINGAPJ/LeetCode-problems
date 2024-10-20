int spf[1000001];
bool isInit = false;
void init(){
    memset(spf, 0, sizeof(spf));
    for(int i = 2; i <= 1e6; i++){
        if(i*i > 1e6)
            break;
        for(int j = i*i; j <= 1e6; j += i)
            if(spf[j] == 0)
                spf[j] = i;   
    }
}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(!isInit){
            init();
            isInit = true;
        }
        int ret = 0;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] <= nums[i+1])
                continue;
            while(spf[nums[i]] != 0 && (nums[i] > nums[i+1])){
                nums[i] = spf[nums[i]];
                ret++;
            }
            if(nums[i] > nums[i+1])
                return -1;
        }
        return ret;
    }
};