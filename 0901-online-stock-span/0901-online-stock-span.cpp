class StockSpanner {
public:
    vector<int> v;
    int prev = -1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        int i = v.size() -1;
        if(i >= 0 && price == v[i])
        {
            v.push_back(price);
            count = prev + 1;
            prev = count;
            return count;
        }
        while( i >= 0){
            if(v[i] <= price)
            {
                count++;
                i--;
            }
            else
            {
                break;
            }
        }
        v.push_back(price);
        prev = count;
        return count;
    }
};
