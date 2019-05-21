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
    int lastStoneWeight(vector<int>& S) {
		while(S.size()>=2) {
			sort(ALL(S));
			int x=S.back();
			S.pop_back();
			int y=S.back();
			S.pop_back();
			if(x!=y) S.push_back(x-y);
			
		}
        if(S.empty()) return 0;
        else return S[0];
    }
};

