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

int num[1010];

class Solution {
public:
    int ispred(string A,string B) {
		if(B.size()!=A.size()+1) return 0;
		int x=0;
		FORR(c,B) {
			if(A[x]==c) x++;
			if(x==A.size()) return 1;
		}
		return 0;
	}
    int longestStrChain(vector<string>& W) {
		vector<int> C[17];
		int i;
		ZERO(num);
		FOR(i,W.size()) {
			C[W[i].size()].push_back(i);
			num[i]=1;
		}
		
		int ma=1;
		for(i=1;i<=15;i++) {
			FORR(a,C[i]) FORR(b,C[i+1]) {
				if(ispred(W[a],W[b])) num[b]=max(num[b],num[a]+1);
				ma=max(ma,num[b]);
			}
		}
		return ma;
        
    }
};

