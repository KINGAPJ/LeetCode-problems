struct job{
    int arr, burst, id;
};
class Solution {
public:
    static bool cmp(job a, job b){
        return a.arr < b.arr;
    }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<job> tasks_;
        for(int i = 0; i < n; i++)
            tasks_.push_back({tasks[i][0], tasks[i][1], i});
        stable_sort(tasks_.begin(), tasks_.end(), cmp);
        vector<int> job_q;
        set<pair<int, int>> ready_q;
        long long currtime = tasks_[0].arr;
        int ind = 0;
        while(ind < n && tasks_[ind].arr == currtime){
            ready_q.insert({tasks_[ind].burst, tasks_[ind].id});
            ind++;
        }
        while(ind < n || ready_q.size()){
            if(ready_q.empty()){
                currtime = tasks_[ind].arr;
                while(ind < n && tasks_[ind].arr == currtime){
                    ready_q.insert({tasks_[ind].burst, tasks_[ind].id});
                    ind++;
                }
            }
            auto u = ready_q.begin();
            currtime += u->first;
            job_q.push_back(u->second);
            while(ind < n && tasks_[ind].arr <= currtime){
                ready_q.insert({tasks_[ind].burst, tasks_[ind].id});
                ind++;
            }
            ready_q.erase(u);
        }
        return job_q;
    }
};