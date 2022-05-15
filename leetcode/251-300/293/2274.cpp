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
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        special.push_back(bottom-1);
        special.push_back(top+1);
        sort(ALL(special));
        int ma=0;
        int i;
        FOR(i,special.size()-1) ma=max(ma,special[i+1]-special[i]-1);
        return ma;
    }
};
