class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> curr_ans;
        for(auto x: tokens){
            if(isdigit(x.back()))
                curr_ans.push(stoi(x));
            else{
                long long b = curr_ans.top(); curr_ans.pop();
                long long a = curr_ans.top(); curr_ans.pop();
                long long curr;
                if(x == "+")
                    curr = a + b;
                else if(x == "-")
                    curr = a - b;
                else if(x == "*")
                    curr = a * b;
                else
                    curr = a / b;
                curr_ans.push(curr);
            }
        }
        long long ans = curr_ans.top();
        return ans;
    }
};