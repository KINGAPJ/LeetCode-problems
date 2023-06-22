#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    map<int, int> a;
	    for(int i = 0; i < n; i++){
	        int x; cin>>x;
	        a[x]++;
	    }
	    vector<pair<int, int>> b;
	    for(auto &i: a){
	        b.push_back({i.second, i.first});
	    }
	    sort(b.begin(), b.end(), [&](pair<int, int>&a, pair<int, int>&b){
	        if(a.first == b.first)
	            return a.second < b.second;
	        else
	            return a.first > b.first;
	    });
	    for(auto &i: b){
	        for(int j = 0; j < i.first; j++){
	            cout<<i.second<<' ';
	        }
	    }
	    cout<<'\n';
	}
	return 0;
}