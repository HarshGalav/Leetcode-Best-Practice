class Solution {
public:
    vector<int> f1(int n) {
        vector<int> freq(10, 0);
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }
        return freq;
    }

    bool f2(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < 10; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> temp = f1(n);
        for (int i = 0; i <= 30; i++) {
            int n2 = 1 << i; 
            vector<int> freq2 = f1(n2);
            if (f2(freq2, temp)) return true;

        }
        return false;
    }
};
