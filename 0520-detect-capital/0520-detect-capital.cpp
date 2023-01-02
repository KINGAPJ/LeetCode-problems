class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1)
            return true;
        if(word[1] >= 'A' && word[1] <= 'Z'){
            int i = 2;
            if(word[0] >= 'a' && word[0] <= 'z')
                return false;
            while(i < word.size())
                if(word[i] >= 'A' && word[i] <= 'Z')
                    i++;
                else return false;
        }else{
            int i = 2;
            while(i < word.size())
                if(word[i] >= 'a' && word[i] <= 'z')
                    i++;
                else return false;
        }
        return true;
    }
};