class Solution {
public:
    int numJewelsInStones(string j, string s) {
        set<char> st;
        for(char ch:j) st.insert(ch);
        int ans = 0;
        for(char ch:s) if(st.find(ch) != st.end()) ans++;
        return ans;
    }
};
