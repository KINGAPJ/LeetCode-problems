class DetectSquares {
    map<vector<int>, int> s;
public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        s[point]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        for(auto &i: s){
            int x1 = i.first[0],  y1 = i.first[1];
            int x4 = point[0],  y4 = point[1];
            if(x1 != x4 && abs(x1-x4) == abs(y1-y4)){
                if(s.count({x1, y4}) && s.count({x4, y1})){
                    ans += (s[{x1, y4}] * s[{x4, y1}] * i.second);
                }
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */