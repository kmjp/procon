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

int S[101010];
class Solution {
	public:
    int minSwaps(vector<int>& data) {
		int N=data.size();
		int i;
		FOR(i,N) {
			S[i+1]=S[i]+(data[i]==1);
		}
		int M=S[N];
		int ma=0;
		for(i=0;i+M<=N;i++) ma=max(ma,S[i+M]-S[i]);
		return M-ma;
    }};

