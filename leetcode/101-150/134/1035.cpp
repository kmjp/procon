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

int dpdp[2020][2020];

int lcs(vector<int>& AA,vector<int>& BB) {
	int x,y,ma=0;
	ZERO(dpdp);
	
	FOR(x,AA.size()) FOR(y,BB.size()) {
		if(AA[x]==BB[y]) dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y]+1);
		dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y+1]);
		dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x+1][y]);
		ma=max(ma,dpdp[x+1][y+1]);
	}
	return ma;
}

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        return lcs(A,B);
    }
};

