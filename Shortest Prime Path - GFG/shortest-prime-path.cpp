//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
bool prime[10000];
class Solution{   
    bool vis[10000];
  public:
    Solution(){
        memset(prime, true, sizeof(prime));
        for(int i = 2; i <= 100; i++)
            if(prime[i])
                for(int j = i*i; j <= 10000; j += i)
                    prime[j] = false;
    }
    int shortestPath(int n1,int n2){   
        // Complete this function using prime vector
        if(!prime[n1] || !prime[n2])
            return -1;
        if(n1 == n2)
            return 0;
        // for(int i = 1000; i < 10000; i++){
        //     cout<<"i: "<<i<<":"<<prime[i]<<'\n';
        // }
        memset(vis, false, sizeof(vis));
        queue<vector<int>> q;
        q.push({n1, 0});
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            int curr = u[0], moves = u[1];
            if(curr == n2)
                return moves;
            vis[curr] = true;
            // cout<<"c: "<<curr<<"m: "<<moves<<'\n';
            for(int j = 0; j < 4; j++){
                int place = pow(10, j);
                int base = curr - ((curr/place) % 10) * place;
                for(int i = 0; i < 10; i++){
                    int num = base + i*place;
                    if(num >= 1000 && num <= 9999 && !vis[num] && prime[num]){
                        q.push({num, moves+1});
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends