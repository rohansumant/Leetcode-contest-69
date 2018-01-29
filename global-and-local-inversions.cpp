const int N = 5005;
int bit[N];
class Solution {
public:
    int n;
    
    int get(int x) {
        int ans = 0;
        while(x) {
            ans += bit[x];
            x -= x & (-x);
        }
        return ans;
    }
    
    void update(int x) {
        while(x <= n) {
            bit[x] += 1;
            x += x & (-x);
        }
    }
    
    bool isIdealPermutation(vector<int>& a) {
        memset(bit,0,sizeof(bit));
        for(int &i:a) i++;
        n = a.size();
        int gi = 0, li = 0;
        for(int i=0;i<n;i++) {
            gi += get(n) - get(a[i]);
            update(a[i]);
        }
        for(int i=1;i<n;i++) {
            li += a[i-1] > a[i];
        }
        return li == gi;
    }
};
