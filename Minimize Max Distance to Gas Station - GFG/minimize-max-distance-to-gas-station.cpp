//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int K){
        double eps = 1e-6;
        double maxx = 0;
        int n = stations.size();
        // for(int i = 1; i < n; i++)
        //     maxx = max((double)stations[i] - stations[i-1], maxx);
        double lo = 0, mid, ans = 0;
        double hi = stations[n-1] - stations[0];
        while(hi - lo > eps){
            mid = lo + (hi - lo)/2;
            int sts = 0;
            for(int i = 0; i < n-1; i++){
                sts += (stations[i+1] - stations[i])/mid;
                // double dist = stations[i] - stations[i-1];
                // sts += (ceil(dist/mid)-1);
            }
            if(sts > K){
                lo = mid;
            }else{
                hi = mid;
                ans = mid;
            }
        }
        return round(ans*100)/100;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends