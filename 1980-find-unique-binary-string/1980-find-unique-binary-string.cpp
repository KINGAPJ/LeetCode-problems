class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> ns;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int num = stoi(nums[i], nullptr, 2);
            ns.insert(num);
        }
        for(int i = 0; i < 17; i++){
            if(!ns.count(i)){
                string binary = bitset<16>(i).to_string();
                return binary.substr(16-n, n);
            }
        }
        return "0";
    }
};