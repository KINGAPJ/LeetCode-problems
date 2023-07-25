class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        int maxele = -1, ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(arr[mid] > arr[mid+1]){
                if(arr[mid] > maxele){
                    maxele = arr[mid];
                    ans = mid;
                }
                hi = mid-1;
            }else{
                if(arr[mid+1] > maxele){
                    maxele = arr[mid+1];
                    ans = mid+1;
                }
                lo = mid+1;
            }
        }
        return ans;
    }
};