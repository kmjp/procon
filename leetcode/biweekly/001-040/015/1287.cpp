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
    int findSpecialInteger(vector<int>& arr) {
        map<int,int> M;
        FORR(a,arr) M[a]++;
        int ma=0,id=0;
        FORR(m,M) if(m.second>ma) id=m.first, ma=m.second;
        return id;
    }
};


