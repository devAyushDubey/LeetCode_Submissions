class Solution {
public:
    
    double power(double x, int n,double &i){
        if(n==1)
            return x;
        if(x==0 || x==1)
            return x;
        //cout<<x<<" "<<n<<endl;
        return power(x*i,n-1,i);
    }
    
    double myPow(double x, int n) {
        
        if(n==0 || x==1)
            return 1;
            
        if(x==0)
            return 0;
        
        if(n<0){
            if(n==INT_MIN){
                n = INT_MAX;
                x = (1 / x);
                x = x*x;
            }
            else{
                x = (1 / x);
                n = (-1)*n;
            } 
        }
        
        if(x==-1){
            if(n%2==0)
                return (-1)*x;
            return x;
        }
        
        return power(x,n,x);
    }
};