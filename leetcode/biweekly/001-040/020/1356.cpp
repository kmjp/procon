typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> V;
        FORR(a,arr) V.push_back({__builtin_popcount(a),a});
        sort(ALL(V));
        vector<int> A;
        FORR(v,V) A.push_back(v.second);
        return A;
    }
};
