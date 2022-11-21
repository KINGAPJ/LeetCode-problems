class Solution {
public:
    int pairpos(int n){return n&1 ? n-1 : n+1;}
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), i = 0;
        unordered_map<int, int> pos;
        int donn = 0; //req: 1<<(n/2) - 1
        for(int i = 0; i < n; i++){
            pos[row[i]] = i;
            if(i&1){
                if(row[i]/2 == row[i-1]/2)
                    donn |= (1<<(i/2));
            }
        }
        i = 0;
        while(i < n && row[i]/2 == row[i+1]/2)
            i += 2;
        if(i >= n)
            return 0;
        int swaps = 0;
        while(donn != (1<<(n/2)) - 1){
            int next = row[pairpos(i)];
            swap(pos[row[pairpos(i)]], pos[pairpos(row[i])]);
            swap(row[pos[row[pairpos(i)]]], row[pos[pairpos(row[i])]]);
            donn |= (1<<(i/2));
            swaps++;
            i = pos[next];
            if(row[i]/2 == row[pairpos(i)]/2){
                donn |= (1<<(i/2));
                for(int j = 0; j < n/2; j++){
                    if(!(donn & (1<<j))){
                        i = 2*j;
                        break;
                    }
                }
            }
        }
        return swaps;
    }
};