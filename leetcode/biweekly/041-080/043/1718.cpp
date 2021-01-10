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


vector<int> R;
int A[50],N;
class Solution {
public:
	void dfs(int cur,int mask) {
		if(R.size()) return;
		if(cur==2*N-1) {
			int i;
			FOR(i,2*N-1) R.push_back(A[i]);
			return;
		}
		if(A[cur]) {
			dfs(cur+1,mask);
		}
		else {
			int i;
			for(i=19;i>=0;i--) if(mask&(1<<i)) {
				if(i==0) {
					A[cur]=i+1;
					dfs(cur+1,mask^(1<<i));
					A[cur]=0;
				}
				else {
					if(cur+(i+1)>=2*N-1) continue;
					if(A[cur+(i+1)]) continue;
					A[cur]=A[cur+(i+1)]=i+1;
					dfs(cur+1,mask^(1<<i));
					A[cur]=A[cur+(i+1)]=0;
				}
			}
		}
		
	}
    vector<int> constructDistancedSequence(int n) {
		R.clear();
		ZERO(A);
		N=n;
		dfs(0,(1<<N)-1);
		return R;
    }
};

