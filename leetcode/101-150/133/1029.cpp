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
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<pair<int,vector<int>>> V;
        int y,x;
        FOR(y,R) FOR(x,C) V.push_back({abs(y-r0)+abs(x-c0),{y,x}});
        sort(ALL(V));
        vector<vector<int>> ret;
        FORR(v,V) ret.push_back(v.second);
        return ret;
    }
};

