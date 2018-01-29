int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

class Solution {
public:
    
    string hash(vector<vector<int>> a) {
        string ans;
        for(int i=0;i<2;i++) for(int j=0;j<3;j++) ans += to_string(a[i][j]);
        return ans;
    }
    
    int slidingPuzzle(vector<vector<int>>& a) {
        priority_queue<pair<int,string>> Q;
        Q.push({0,hash(a)});
        set<string> s;
        vector<vector<int>> b(2,vector<int>(3));
        while(!Q.empty()) {
            auto pr = Q.top(); Q.pop();
            int cost = -pr.first;
            string h = pr.second;
            
            if(h == "123450") return cost;
            if(s.find(h) != s.end()) continue;
            s.insert(h);
            
            
            for(int i=0;i<6;i++) {
                b[i/3][i%3] = h[i]-'0';
            }
            
            int x,y;
            for(int i=0;i<2;i++) for(int j=0;j<3;j++) if(b[i][j] == 0) {
                x = i; y = j;
                break;
            }
            for(int i=0;i<4;i++) {
                int _x = x+dx[i], _y = y+dy[i];
                if(_x >= 0 & _y >= 0 && _x < 2 && _y < 3) {
                    swap(b[x][y],b[_x][_y]);
                    Q.push({-(cost+1),hash(b)});
                    swap(b[x][y],b[_x][_y]);
                }
            }
            
        }
        return -1;
    }
};
