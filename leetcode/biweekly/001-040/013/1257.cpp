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

map<string,string> P;

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        P.clear();
        FORR(r,regions) {
			int i;
			for(i=1;i<r.size();i++) P[r[i]]=r[0];
		}
		vector<string> A[2];
		while(1) {
			A[0].push_back(region1);
			if(P.count(region1)==0) break;
			region1=P[region1];
		}
		while(1) {
			A[1].push_back(region2);
			if(P.count(region2)==0) break;
			region2=P[region2];
		}
		reverse(ALL(A[0]));
		reverse(ALL(A[1]));
		int i;
		string ret;
		FOR(i,min(A[0].size(),A[1].size())) {
			if(A[0][i]==A[1][i]) ret=A[0][i];
		}
		return ret;
    }
};



