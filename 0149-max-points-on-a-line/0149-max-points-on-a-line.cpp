class Solution {
public:
    /*
    
    
                                            A
                                 Very Batshit Implementation
    
    
    
    
    */
    int horizontal_lines = 0, n;
    map<pair<int, int>, int> lines;
    vector<vector<int>> pts;
    pair<int, int> slope(vector<int> &a, vector<int> &b){
        int x = a[0] - b[0];
        int y = a[1] - b[1];
        if(x == 0){ return {0,0}; }
        else if(y == 0){ return {INT_MAX, INT_MAX}; }
        else if(y < 0) { x = -x; y = -y; }
        int coprimer = gcd(x, y);
        return make_pair(x/coprimer, y/coprimer);
    }
    int addline(vector<int> &a, vector<int> &b, int count){
        if(a[1] == b[1]){
            horizontal_lines += 1;
            count = max(count, horizontal_lines);
        }else{
            auto slp = slope(a, b);
            if(lines.count(slp))
                lines[slp]++;
            else lines[slp] = 2;
            count = max(count, lines[slp]);
        }
        return count;
    }
    int mx_pts(int i){ //max pts on a line containing point i
        lines.clear();
        horizontal_lines = 1;
        int count = 1;
        for(int j = i+1; j < n; j++)
            count = addline(pts[i], pts[j], count);
        return count;
    }
    int maxPoints(vector<vector<int>>& pts) {
        this->pts = pts;
        n = pts.size();
        if(n <= 2)
            return n;
        int ans = 1;
        for(int i = 0; i < n-1; i++)
            ans = max(ans, mx_pts(i));
        return ans;
    }
};