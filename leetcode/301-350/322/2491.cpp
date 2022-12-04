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
    long long dividePlayers(vector<int>& skill) {
        sort(ALL(skill));
        int i,N=skill.size();
        FOR(i,N) if(skill[i]+skill[N-1-i]!=skill[0]+skill[N-1]) return -1;
        ll ret=0;
        FOR(i,N/2) ret+=1LL*skill[i]*skill[N-1-i];
        return ret;
    }
};
