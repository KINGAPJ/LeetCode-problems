class Solution {
public:
    /*
s = kyfqvhwfufejafs  t = eff
counter remains >0 unless we reach e.. by which time.. k = -1, y = -1...
by the time left reaches f.. everything will become 0 only after being checked for 0
    */
    string minWindow(string s, string t) {
        int frq[256] = {0};
        for(int i = 0; i < t.size(); i++)
            frq[t[i]]++;
        int counter = t.size(); //count of letters remaining to be checked in window
        int l = 0, r = 0, start = 0, length = INT_MAX;
        while(r < s.size()){
            if(frq[s[r]] > 0)
                counter--; //letter got checked in t.. now remove it..
            frq[s[r]]--; //for other letters to be later removed from left side..
                //to reduce the length of substring
            r++;
            while(counter == 0){ //if the current window is valid.. 
                //we remove unnecessary chars until we find necessary
                if(r - l < length){
                    length = r - l;
                    start = l;
                }
                if(frq[s[l]] == 0)
                    counter++;
/*if a minussed letter comes back to 0 (within or out of t).. it means window has become invalid..
this is because.. it is being checked before being replenished back.. 
so the count of unnecessary letters will never reach 0 before coming to a necessary letter*/
                frq[s[l]]++;
                l++;
            }
        }
        return (length == INT_MAX) ? "" : s.substr(start, length);
    }
};