class Solution {
    /*
    Start traversing from the end of array

if current no is divisible by the previous number and suppose
current no is a, and prev no is b,
the we must need to divide current number(a) to a/b-1 times

suppose current number is 9 and previous number is 3,
then we can divide it into 9/3 times-1,
in this case prev remains same (No need to update)

now suppose if prev number is not divisible by current number,
suppose current is 7 prev is 5,
so we can divide 7 into
2 ,5
3, 4
out of this 3,4 is best choice ,

and for every element we have to add noOfTime to our ans,
i.e, no of times we need to divide a current element,
    */
public:
    #define ll long long
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0, prev = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            int noOfTime = nums[i]/prev;   
            if(nums[i] % prev != 0)
                prev = nums[i]/(++noOfTime);
            ans += noOfTime-1;
        }
        return ans;
    }
};