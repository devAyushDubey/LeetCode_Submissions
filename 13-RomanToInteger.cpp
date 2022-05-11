class Solution {
public:
    int romanToInt(string s) {
        int sum = 0,i=0;
        while(i<s.length()){
            if(s[i]=='I'){
                if(i!=s.length()-1){
                    if(s[i+1]=='V'){
                        sum += 4;
                        i += 2;
                        continue;
                    }
                    else if(s[i+1]=='X'){
                        sum += 9;
                        i += 2;
                        continue;
                    }
                }
                sum += 1;
            }
            else if(s[i]=='V')
                sum += 5;
            else if(s[i]=='X'){
                if(i!=s.length()-1){
                    if(s[i+1]=='L'){
                        sum += 40;
                        i += 2;
                        continue;
                    }
                    else if(s[i+1]=='C'){
                        sum += 90;
                        i += 2;
                        continue;
                    }
                }
                sum += 10;
            }
            else if(s[i]=='L')
                sum += 50;
            else if(s[i]=='C'){
                if(i!=s.length()-1){
                    if(s[i+1]=='D'){
                        sum += 400;
                        i += 2;
                        continue;
                    }
                    else if(s[i+1]=='M'){
                        sum += 900;
                        i += 2;
                        continue;
                    }
                }
                sum += 100;
            }
            else if(s[i]=='D')
                sum += 500;
            else
                sum += 1000;
            i++;
        }
        return sum;
    }
};