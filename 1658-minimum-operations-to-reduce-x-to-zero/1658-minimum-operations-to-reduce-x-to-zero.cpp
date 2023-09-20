class Solution {
public:
    //https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/discuss/2137299/Binary-Search-or-c%2B%2B-or-O(nlogn)
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        
        vector<long> pre(n+1,0);
        
        int noOfOperation = n+1;
        
        //calculate the prefixsum
        for(int i=0;i<n;i++){
            pre[i+1] = pre[i] + nums[i];
        }
        
        
        int suff = 0;
        
        for(int i=n;i>=0;i--){
            
            int s = 0, e = i;
            
            //apply binary search and find the x-suff index
            while(s<=e){
                
                int m = (s+e)>>1;
                
                if(pre[m]==x-suff){
                    noOfOperation = min(noOfOperation,m+(n-i));
                    break;
                }else if(pre[m]>x-suff){
                    e = m-1;
                }else
                    s = m+1;
            }  
            
            if(i-1>=0) suff += nums[i-1];
        }
        
        return noOfOperation==n+1?-1:noOfOperation;
    }
};