class ExamRoom {
public:    
    ExamRoom(int n) : _s([this](const Data& lhs, const Data& rhs) -> bool
	{
            int lhsLen = lhs.len <= 0 ? -1 : (lhs.len - 1) / 2;
            int rhsLen = rhs.len <= 0 ? -1 : (rhs.len - 1) / 2;

            if(auto it = this->_m.find(lhs.idx); it != this->_m.end() && it == this->_m.begin() || it == prev(this->_m.end()))
            {
                lhsLen = lhs.len - 1;
            }

            if(auto it = this->_m.find(rhs.idx); it != this->_m.end() && it == this->_m.begin() || it == prev(this->_m.end()))
            {
                rhsLen = rhs.len - 1;
            }

            return lhsLen == rhsLen ? lhs.idx < rhs.idx : lhsLen > rhsLen;
        })
    {
        Data imaginary; // will never be accessed by user of class
        imaginary.idx = -1;
        imaginary.len = n;
        
        _m[imaginary.idx] = _s.insert(imaginary).first;
    }
    
    int seat()
    {
        auto it = _s.begin();
        
        if(it->len == 0)
            throw runtime_error("no empty seats");
        
        Data pre = *it;
        
        Data data;        
        if(auto it2 = _m.find(pre.idx); it2 == _m.begin())
        {
            data.idx = 0;
            data.len = pre.len - 1;
        } else if(it2 == prev(_m.end()))
        {
            Data last = *prev(_m.end())->second;
            int n = last.idx + last.len + 1; // the very same value as in constructor
            data.idx = n - 1;
            data.len = 0;
        } else
        {
            data.idx = pre.idx + (pre.len + 1) / 2;
            data.len = pre.len / 2;
        }
        
        pre.len -= data.len + 1;
        _s.erase(it);
        _m[data.idx] = _s.insert(data).first;
        _m[pre.idx] = _s.insert(pre).first; // update _m
        
        return data.idx;
    }
    
    void leave(int p)
    {
        auto it = _m.find(p);
        auto pre = prev(it);
        
        Data data = *pre->second;
        _s.erase(pre->second);
        data.len += (*it->second).len + 1;
        _s.erase(it->second);
        _m.erase(it);
        _m[data.idx] = _s.insert(data).first; // update _m
    }

private:
    struct Data
    {
        int idx; // seat occupied by student
        int len; // free seats to the right of idx
    };
    
    map<int, set<Data>::iterator> _m; // idx -> idx position in priority queue
    set<Data, function<bool(const Data&, const Data&)>> _s; // priority queue
};