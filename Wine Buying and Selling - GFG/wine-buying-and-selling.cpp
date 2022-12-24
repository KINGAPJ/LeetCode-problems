//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#define ll long long
class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      //Code here.
      deque<pair<ll,ll>> se, bu;
      ll ans = 0;
      for(int i = 0; i < N; i++){
          if(Arr[i] < 0){
              while(bu.size()){
                  auto u = bu.front();
                  bu.pop_front();
                  if(u.first < abs(Arr[i])){
                      Arr[i] += u.first;
                      ans += (i-u.second)*u.first;
                  }else{
                      ans += (i-u.second)*abs(Arr[i]);
                      u.first -= abs(Arr[i]);
                      Arr[i] = 0;
                      if(u.first)
                        bu.push_front(u);
                    //   cout<<"u: "<<u.first<<'-'<<u.second<<endl;
                      break;
                  }
              }
              if(Arr[i]){
                  se.push_back({abs(Arr[i]),i});
              }
          }else if(Arr[i] > 0){
              while(se.size()){
                  auto u = se.front();
                  se.pop_front();
                  if(u.first < Arr[i]){
                      Arr[i] -= u.first;
                      ans += (i-u.second)*u.first;
                  }else{
                      ans += (i-u.second)*abs(Arr[i]);
                      u.first -= abs(Arr[i]);
                      Arr[i] = 0;
                      if(u.first)
                        se.push_front(u);
                        // cout<<"u: "<<u.first<<'-'<<u.second<<endl;
                      break;
                  }
              }
              if(Arr[i]){
                  bu.push_back({abs(Arr[i]),i});
              }
          }
        //   cout<<"ans: "<<ans<<endl;
      }
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends