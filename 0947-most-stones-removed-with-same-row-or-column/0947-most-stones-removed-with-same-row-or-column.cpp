class Solution {
public:
    //https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands-O(N)
    unordered_map<int, int> f;
    int islands = 0;

    int find(int x) {
        if (!f.count(x)) f[x] = x, islands++;
        if (x != f[x]) f[x] = find(f[x]);
        return f[x];
    }
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) f[x] = y, islands--;
    }
    
    //key insights: number of islands is the answer
    //how to make islands: if we make row of a pt the root ancestor of the column..
    //  then any pt with same column will find the same column as an ancestor of the first pt
    //  in consideration, whose root ancestor is the row
    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < stones.size(); ++i)
            uni(stones[i][0], ~stones[i][1]); // ~: 1's complement
        return stones.size() - islands;
    }
};