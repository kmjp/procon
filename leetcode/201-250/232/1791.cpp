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
    int findCenter(vector<vector<int>>& edges) {
		map<int,int> M;
		FORR(e,edges) {
			M[e[0]]++;
			M[e[1]]++;
			if(M[e[0]]>1) return e[0];
			if(M[e[1]]>1) return e[1];
		}
        return 0;
    }
};
