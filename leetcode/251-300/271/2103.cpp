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
    int countPoints(string rings) {
		int C[3][10]={};
		int i;
		FOR(i,rings.size()/2) {
			if(rings[i*2]=='R') C[0][rings[i*2+1]-'0']++;
			if(rings[i*2]=='G') C[1][rings[i*2+1]-'0']++;
			if(rings[i*2]=='B') C[2][rings[i*2+1]-'0']++;
		}
		int ret=0;
		FOR(i,10) {
			if(C[0][i]&&C[1][i]&&C[2][i]) ret++;
		}
		return ret;
        
    }
};
