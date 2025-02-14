class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    vector<int>ans;
    long long all=1;
    vector<long long>temp;
    int zero=-1;
    void add(int num) {
        ans.push_back(num);
        // all=all*num;
        if(num==0){
            all=1;
            zero=ans.size()-1;
        }
        else{
            all=all*num;
        }
        temp.push_back(all);


    }
    
    int getProduct(int k) {
        int n = ans.size();
        if (zero >= n - k) {
            return 0; 
        }
        if (n - k == 0) {
            return temp[n - 1]; 
        }
        return temp[n - 1] / temp[n - k - 1]; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */