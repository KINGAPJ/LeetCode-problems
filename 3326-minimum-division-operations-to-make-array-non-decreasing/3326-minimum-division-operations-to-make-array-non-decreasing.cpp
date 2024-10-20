int v[1000001];
bool isInit = false;
void init(){
    for(int i = 1; i <= 1e6; i++)
        for(int j = 2*i; j <= 1e6; j += i)
            v[j] = i;
}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(!isInit){
            init();
            isInit = true;
        }
        int a = 0;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] <= nums[i+1])
                continue;
            while((nums[i]/v[nums[i]]) != nums[i] && (nums[i] > nums[i+1])){
                nums[i] /= v[nums[i]];
                a++;
            }
            if(nums[i] > nums[i+1])
                return -1;
        }
        return a;
    }
};