class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int aliceChances = 0, bobChances = 0;
        
        int countA=0,countB=0;
        
        for(int i=0;i<colors.length();i++){
            if(colors[i]=='A'){
                countB = 0;
                if(countA++>=2) aliceChances++;
            }
            else{
                countA = 0;
                if(countB++>=2) bobChances++;
            }
        }
        
        if(aliceChances>bobChances)
            return true;
        
        return false;
    }
};