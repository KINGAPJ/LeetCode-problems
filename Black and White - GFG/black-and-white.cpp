//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
int dr[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dc[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const long long mod = 1e9 + 7;
bool isV(int i, int j, int n, int m){
    return i >= 0 && i < n && j >= 0 && j < m;
}
long long numOfWays(int n, int m){
    // write code here
    long long maxx = m*n - 1;
    long long res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            long long curr = maxx;
            for(int k = 0; k < 8; k++){
                int r = i + dr[k], c = j + dc[k];
                if(isV(r, c, n, m)){
                    curr--;
                }
            }
            res = (res + curr) % mod;
        }
    }
    return res % mod;
}