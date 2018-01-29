//upsolved
class Solution {
public:
    vector<int> a;
    int k,n;
    
    bool check(double x) {
        int cnt = k;
        for(int i=1;i<n;i++) {
            cnt -= ceil((a[i]-a[i-1])/x)-1;
        }
        return cnt >= 0;
    }
    
    double minmaxGasDist(vector<int>& _a, int _k) {
        a = _a; k = _k;
        double l = 0, r = 0;
        n = a.size();
        for(int i=1;i<n;i++) r = max(r,1.0*a[i]-a[i-1]);
        if(!k) return r;
        
        for(int i=0;i<100;i++) {
            double m = (l+r)/2.0;
            if(check(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        return (l+r)/2.0;
    }
};
