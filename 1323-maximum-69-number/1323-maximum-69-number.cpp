class Solution {
public:
    int maximum69Number (int num) {
        
        int temp = num;
        int pos_6 = 0;
        int i = 1;
        
        while(temp){
            int digit = temp%10;
            if(digit == 6){
                pos_6 = i;
            }
            temp /= 10;
            i *= 10;
        }
        
        num -= (pos_6*6);
        num += (pos_6*9);
        
        return num;
    }
};