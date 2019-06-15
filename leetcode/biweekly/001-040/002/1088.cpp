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

vector<vector<int>> S[12];

class Solution {
	public:
	int rotate(int C) {
		int R=0;
		int V[10];
		V[0]=0;
		V[1]=1;
		V[6]=9;
		V[8]=8;
		V[9]=6;
		while(C) {
			R=R*10+V[C%10];
			C/=10;
		}
		return R;
	}
	
    int confusingNumberII(int N) {
		
		if(S[1].empty()) {
			S[1]={{0,0},{1,0},{6,1},{8,0},{9,1}};
			int i;
			for(i=1;i<=8;i++) {
				FORR(s,S[i]) if(s[0]) {
					S[i+1].push_back({s[0]*10,rotate(s[0]*10)!=s[0]*10});
					S[i+1].push_back({s[0]*10+1,rotate(s[0]*10+1)!=s[0]*10+1});
					S[i+1].push_back({s[0]*10+6,rotate(s[0]*10+6)!=s[0]*10+6});
					S[i+1].push_back({s[0]*10+8,rotate(s[0]*10+8)!=s[0]*10+8});
					S[i+1].push_back({s[0]*10+9,rotate(s[0]*10+9)!=s[0]*10+9});
				}
			}
			S[10]={{1000000000,1}};
		}
		int ret=0;
		for(int i=1;i<=10;i++) FORR(s,S[i]) if(s[0]<=N) ret+=s[1];
		return ret;
    }
};

