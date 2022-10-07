class MyCalendarThree {
public:
    map<int,int>m;
    MyCalendarThree() {}
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int maxi=0,sum=0;
        for(auto &a:m){
            sum+=a.second;
            maxi=max(maxi,sum);
        }
        return maxi;
    }  
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */