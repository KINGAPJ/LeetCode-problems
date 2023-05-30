//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<vector<char>> M;
    string w;
    int ds[5] = {0, -1, 0, 1, 0};
public:
    bool isv(int i, int j){
        return i >= 0 && i < M.size() && j >= 0 && j < M[0].size();
    }
    bool f(int i, int j, int k){
        int n = w.size();
        if(k >= n)
            return true;
        bool ret = false;
        for(int x = 0; x < 4; x++){
            int r = i + ds[x], c = j + ds[x+1];
            if(isv(r, c) && M[r][c] == w[k]){
                char t = M[r][c];
                M[r][c] = '#';
                ret |= f(r, c, k+1);
                M[r][c] = t;
            }
        }
        return ret;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        M = board; w = word;
        int m = M.size(), n = M[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(M[i][j] == word[0]){
                    char t = M[i][j];
                    M[i][j] = '#';
                    if(f(i, j, 1))
                        return true;
                    M[i][j] = t;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends