class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, int> content;
        int ind = 0;
        vector<vector<string>> ans;
        for(auto &i: paths){
            string folder = "";
            int j = 0;
            while(i[j] != ' ')
                folder.push_back(i[j++]);
            j++; //to go to file
            while(j < i.size()){
                string file = "";
                while(i[j] != '(')
                    file.push_back(i[j++]);
                j++; //to go to content
                string text = "";
                while(i[j] != ')')
                    text.push_back(i[j++]);
                j+=2; //to go to next file
                if(content.count(text))
                    ans[content[text]].push_back(folder+"/"+file);
                else{
                    content[text] = ind++;
                    ans.push_back({folder+"/"+file});
                }
            }
        }
        vector<vector<string>> finalans;
        for(auto &i: ans){
            if(i.size() > 1)
                finalans.push_back(i);
        }
        return finalans;
    }
};