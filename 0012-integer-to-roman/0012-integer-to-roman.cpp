class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        for(int i = 0; (i < 4) && num; i++){
            if(i == 0){
                switch (num%10){
                    case 1: s += ("I"); break;
                    case 2: s += ("II"); break;
                    case 3: s += ("III"); break;
                    case 4: s += ("VI"); break;
                    case 5: s += ("V"); break;
                    case 6: s += ("IV"); break;
                    case 7: s += ("IIV"); break;
                    case 8: s += ("IIIV"); break;
                    case 9: s += ("XI"); break;
                    case 0: break;
                }
                num/=10;
            }else if(i == 1){
                switch (num%10){
                    case 1: s += ("X"); break;
                    case 2: s += ("XX"); break;
                    case 3: s += ("XXX"); break;
                    case 4: s += ("LX"); break;
                    case 5: s += ("L"); break;
                    case 6: s += ("XL"); break;
                    case 7: s += ("XXL"); break;
                    case 8: s += ("XXXL"); break;
                    case 9: s += ("CX"); break;
                    case 0: break;
                }
                num/=10;
            }else if(i == 2){
                switch (num%10){
                    case 1: s += ("C"); break;
                    case 2: s += ("CC"); break;
                    case 3: s += ("CCC"); break;
                    case 4: s += ("DC"); break;
                    case 5: s += ("D"); break;
                    case 6: s += ("CD"); break;
                    case 7: s += ("CCD"); break;
                    case 8: s += ("CCCD"); break;
                    case 9: s += ("MC"); break;
                    case 0: break;
                }
                num/=10;
            }else{
                switch (num%10){
                    case 1: s += ("M"); break;
                    case 2: s += ("MM"); break;
                    case 3: s += ("MMM"); break;
                    case 0: break;
                }
                num/=10;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};