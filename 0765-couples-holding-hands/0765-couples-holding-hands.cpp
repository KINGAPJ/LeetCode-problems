class Solution {
public:
    int pairpos(int n){return n&1 ? n-1 : n+1;}
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), i = 0;
        unordered_map<int, int> pos;
        // vector<bool> done(n>>1);
        int donn = 0; //req: 1<<(n/2) - 1
        for(int i = 0; i < n; i++){
            pos[row[i]] = i;
            if(i&1){
                if(row[i]/2 == row[i-1]/2)
                    donn |= (1<<(i/2));
                    // done[i/2] = true;
            }
        }
        // cout<<endl;
        // for(auto &x: pos)
        //     cout<<x.first<<":"<<x.second<<" ";
        // cout<<endl;
        i = 0;
        while(i < n && row[i]/2 == row[i+1]/2)
            i += 2;
        if(i >= n)
            return 0;
        int swaps = 0;
        // cout<<"i: "<<i<<endl;
        // cout<<donn<<endl;
        while(donn != (1<<(n/2)) - 1/* && row[i]/2 != row[pairpos(i)]/2*/){
            int next = row[pairpos(i)];
            swap(pos[row[pairpos(i)]], pos[pairpos(row[i])]);
            swap(row[pos[row[pairpos(i)]]], row[pos[pairpos(row[i])]]);
            donn |= (1<<(i/2));
            // for(auto &x: row)
            //     cout<<x<<" ";
            // cout<<endl;
            swaps++;
            // cout<<"i: "<<i<<" next: "<<next<<" pos: "<<pos[next]<<endl;
            i = pos[next];
            if(row[i]/2 == row[pairpos(i)]/2){
                // cout<<"donn: "<<donn<<endl;
                donn |= (1<<(i/2));
                for(int j = 0; j < n/2; j++){
                    if(!(donn & (1<<j))){
                        i = 2*j;
                        break;
                    }
                }
            }
            // cout<<donn<<endl;
        }
        return swaps;
        /*
        vector<bool> done(n>>1);
        for(int i = 0; i < n; i++){
            pos[row[i]] = i;
            if(i&1){
                if(row[i]/2 == row[i-1]/2)
                    done[i/2] = true;
            }
        }
        int swaps = 0;
        for(int i = 0; i < n/2; i++){
            if(!done[i]){
                
            }
        }*/
    }
};