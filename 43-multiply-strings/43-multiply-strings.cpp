class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.front() == '0' or num2.front() == '0')
            return "0";
        int carry = 0, mul = 0, sum = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans = "";
        for(int i = 0; i < num1.size(); i++){
            carry = 0, mul = 0;
            string curr = "";
            for(int j = 0; j < num2.size(); j++){
                int prod = (num2[j] - '0') * (num1[i] - '0') + carry;
                carry = prod / 10;
                mul = prod % 10;
                curr.push_back(mul+'0');
            }
            if(carry)
                curr.push_back(carry+'0');
            carry = 0, sum = 0;
            for(int j = 0; j < curr.size(); j++){
                if(i+j+1 > ans.size())
                    ans.push_back('0');
                sum = (ans[i+j]-'0') + (curr[j]-'0') + carry;
                carry = sum / 10;
                sum %= 10;
                ans[i+j] = sum + '0';
            }
            if(carry)
                ans.push_back(carry+'0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};