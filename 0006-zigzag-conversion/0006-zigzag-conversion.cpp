#include <sstream>
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        //there are 2 patterns in the numbers
        //Row 0 and n: iterator increments by n*2 - 2
        //Other rows: incrementation between iteratora (n*2 - (2* (currentRow + 1))) and iteratorb (2* currentRow)

        stringstream converted;
        for (int i = 0; i < numRows; i++) {

        //Calculating how far in row should iterators move
        int iteratora = (numRows * 2);
        int iteratorb;
        int j = i;
        int loop = 1;

        if (i == 0 || i == numRows - 1) {
            iteratora -= 2;
            iteratorb = iteratora;
        }
        else {
            iteratora -= (2 * (i + 1));
            iteratorb = (2 * (i));
        }

        while(j < s.length()){
            converted << s[j];
            if(loop % 2 == 1){
                j += iteratora;
            } else {
                j += iteratorb;
            }
            
            ++loop;
        }
    }

        return converted.str();
    }
};