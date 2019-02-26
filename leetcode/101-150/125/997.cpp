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
    int findJudge(int N, vector<vector<int>>& trust) {
		int i;
		FOR(i,N) {
			int ok=0;
			int ng=0;
			FORR(t,trust) {
				if(t[0]==i+1) ng=1;
				if(t[1]==i+1) ok++;
			}
			if(ok==N-1&&ng==0) return i+1;
		}
		return -1;
		
        
    }
};
