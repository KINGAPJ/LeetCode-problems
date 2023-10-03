class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector <int> table(101,0);
        for (int i=0; i<nums.size(); i++)
        {
            table[nums[i]]++;
        }
        int pairs=0;
        for (int i=0; i<table.size();i++)
        {
            pairs+=(table[i])*(table[i]-1)/2;
        }
        return pairs;
    }
};