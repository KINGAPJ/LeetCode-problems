class Solution {
public:
    int threeSumClosest(vector<int>& num, int t) {
        int ans = 1e6;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            int target = t-num[i]; // a + b + c = 0.. b + c = -a.. 
            //if b + c < -a then we need sum to increase.. so increase b(sorted order, b: front)
            //otherwise.. otherwise
            int front = i + 1;
            int back = num.size() - 1;
            while (front < back) {
                int sum = num[front] + num[back];
                // Finding answer which start from number num[i]
                if(abs(t-(sum+num[i])) < abs(t-ans))
                ans = sum+num[i];
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else{
                    cout<<"jad";
                    return t;
                }
            }
            // Processing duplicates of Number 1
            while (i < num.size() - 1 && num[i + 1] == num[i]) 
                i++;
        }
        return ans;
    }
};