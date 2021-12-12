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

int L[101010];
int R[101010];
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
		int N=security.size();
		int i;
		FOR(i,N) {
			if(i&&security[i]>security[i-1]) L[i]=1;
			else L[i]=(i?L[i-1]+1:1);
		}
		R[N-1]=1;
		for(i=N-2;i>=0;i--) {
			if(security[i]>security[i+1]) R[i]=1;
			else R[i]=R[i+1]+1;
		}
		vector<int> V;
		FOR(i,N) {
			if(L[i]>=time+1&&R[i]>=time+1) V.push_back(i);
		}
		
        return V;
    }
};
