class Solution {
public:
    string reverseWords(string s) {
//         string::iterator ptr1 = s.begin();
//         string::iterator ptr2 = s.begin();
//         while(ptr2 < s.end()){
//             for(ptr1; *ptr1 != ' '; ptr1++){
//                 ptr2++;
//             }
            
//         }
        int i = 0, j = 0;
        while(j<s.size()) {
            if(j==s.size()-1)
                reverse(s.begin()+i,s.end());
            if(s[j]==' '){
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
                j=j+1;
            }
            else j++;
        }
        return s;
    }
};