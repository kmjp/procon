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


int S[1010][1010];

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        ZERO(S);
        FORR(a,dig) {
			S[a[0]+1][a[1]+1]=1;
		}
		int y,x;
		FOR(y,1001) FOR(x,1001) {
			if(y) S[y][x]+=S[y-1][x];
			if(x) S[y][x]+=S[y][x-1];
			if(y&&x) S[y][x]-=S[y-1][x-1];
		}
		int ret=0;
		FORR(v,artifacts) {
			int num=S[v[2]+1][v[3]+1]-S[v[2]+1][v[1]]-S[v[0]][v[3]+1]+S[v[0]][v[1]];
			if(num==(v[2]-v[0]+1)*(v[3]-v[1]+1)) ret++;
		}
		return ret;
		
    }
};
