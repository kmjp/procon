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
    int oddEvenJumps(vector<int>& A) {
		int N=A.size();
		vector<int> nex[2];
		vector<int> ok[2];
		map<int,int> S;
		int ret=0;
		int i;
		
		nex[0].resize(N);
		nex[1].resize(N);
		ok[0].resize(N);
		ok[1].resize(N);
		for(i=N-1;i>=0;i--) {
			if(i==N-1) {
				ok[0][i]=ok[1][i]=1;
				ret++;
			}
			else if(i<N-1) {
				
				auto it=S.lower_bound(A[i]);
				if(it==S.end()) {
					nex[0][i]=-1;
				}
				else {
					nex[0][i]=it->second;
					if(ok[1][nex[0][i]]) {
						ok[0][i]=1;
						ret++;
					}
				}
				
				it=S.lower_bound(A[i]+1);
				if(it==S.begin()) {
					nex[1][i]=-1;
				}
				else {
					it--;
					nex[1][i]=it->second;
					if(ok[0][nex[1][i]]) {
						ok[1][i]=1;
					}
				}
			}
			S[A[i]]=i;
		}
		return ret;
        
    }
};

