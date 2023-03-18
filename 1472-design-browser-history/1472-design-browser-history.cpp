class BrowserHistory {
    vector<string> history;
    int index = -1;
    int last = -1;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        index = 0;
        last = 0;
    }
    void visit(string url) {
        if(index == history.size()-1){
            history.push_back(url);
            index++;
            last = index;
        }else{
            history[++index] = url;
            last = index;
        }
    }
    string back(int steps) {
        if(steps > index)
            steps = index;
        index -= steps;
        return history[index];
    }
    string forward(int steps) {
        if(steps > last - index)
            steps = last - index;
        index += steps;
        return history[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */