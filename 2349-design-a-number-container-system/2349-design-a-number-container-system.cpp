class NumberContainers {
public:
unordered_map<int,int>idxtonum;
unordered_map<int,set<int>>numtoidx;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
       if(idxtonum.count(index)){
        int prevNum=idxtonum[index];
        numtoidx[prevNum].erase(index);
        if(numtoidx[prevNum].empty()){
            numtoidx.erase(prevNum);
        }
       }
       idxtonum[index]=number;
       numtoidx[number].insert(index);
        
    }
    
    int find(int number) {
        
        if(numtoidx.count(number)){
            return *numtoidx[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */