class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int n = num.size()-1;
        int carry = 0;
        while(k){
            int t = k%10;
            t += carry;
            if(n<0){
                vector<int> vec;
                if(t>9){
                    carry = t/10;
                    t = t%10;
                }
                else{
                    carry = 0;
                }
                vec.push_back(t);
                vec.insert(vec.end(),num.begin(),num.end());
                num = vec;
            }
            else{
                num[n] += t;
                if(num[n] > 9){
                    carry = num[n]/10;
                    num[n] = num[n]%10;
                }
                else{
                    carry = 0;
                }
                
            }
            n--;
            k /= 10;
            
        }
        
        while(carry){
            //cout<<"Carry "<<carry<<"n "<<n<<endl;
            if(n<0){
                vector<int> vec;
                int t = carry;
                if(t > 9){
                    t = carry%10;
                    carry = carry/10;
                }
                else{
                    carry = 0;
                }
                vec.push_back(t);
                vec.insert(vec.end(),num.begin(),num.end());
                num = vec;
            }
            else{
                num[n] += carry;
                if(num[n] > 9){
                    carry = num[n]/10;
                    num[n] = num[n]%10;
                }else{
                    carry = 0;
                }
            }
            n--;
            
        }
        
        return num;
    }
};