class SnapshotArray {
    vector<vector<pair<int, int>>> arr;
    int snap_id;
public:
    SnapshotArray(int length) {
        arr = vector<vector<pair<int, int>>>(length);
        snap_id = 0;
    }
    void set(int index, int val) {
        if(arr[index].size() && arr[index].back().first == snap_id){
            arr[index].back() = {snap_id, val};
        }else{
            arr[index].push_back({snap_id, val});
        }
    }
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    int get(int index, int snap_id) {
        int x = (upper_bound(arr[index].begin(), arr[index].end(), 
                             pair<int, int>{snap_id, INT_MAX}) - arr[index].begin()) - 1;
        if(x < 0)
            return 0;
        else
            return arr[index][x].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */