//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int chenj5 = 0, chenj10 = 0;
        for(int i = 0; i < N; i++){
            if(bills[i] == 5)
                chenj5++;
            else if (bills[i] == 10){
                chenj5--;
                chenj10++;
            }else{
                if(chenj10){
                    chenj10--;
                    chenj5--;
                }else{
                    chenj5-=3;
                }
            }
            if(chenj5 < 0 || chenj10 < 0)
                return false;
        }
        return chenj5 >= 0 && chenj10 >= 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends