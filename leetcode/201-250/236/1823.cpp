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
    int findTheWinner(int n, int k) {
        set<int> S;
        int i;
        FOR(i,n) S.insert(i+1);
        int cur=1;
        auto it=S.begin();
        while(S.size()>1) {
			int i;
			FOR(i,k-1) {
				it++;
				if(it==S.end()) it=S.begin();
			}
			it=S.erase(it);
			if(it==S.end()) it=S.begin();
		}
		return *S.begin();
    }
};
