class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int x = nums1.size();
        int y = nums2.size();
        
        int lo = 0, hi = x;
        while(lo <= hi){
            int partitionX = lo + (hi - lo)/2;
            int partitionY = (x + y + 1)/2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                if((x + y) % 2 == 0)
                    return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
                else return (double)max(maxLeftX, maxLeftY);
            }else if(maxLeftX > minRightY)
                hi = partitionX - 1;
            else
                lo = partitionX + 1;
        }
        return -1;
    }
};