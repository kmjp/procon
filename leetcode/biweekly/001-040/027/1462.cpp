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

int ok[101][101];


class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        ZERO(ok);
        FORR(p,prerequisites) ok[p[0]][p[1]]=1;
        int x,y,z;
        FOR(z,n) FOR(x,n) FOR(y,n) ok[x][y]|=ok[x][z]&&ok[z][y];
        vector<bool> V;
        FORR(q,queries) V.push_back(ok[q[0]][q[1]]);
        return V;
    }
};



