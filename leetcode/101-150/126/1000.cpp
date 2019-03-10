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

int memo[32][32];

class Solution {
public:
	int K;
	vector<int> S,sum;
	
	int dpdp(int L,int R) {
		if((R-L-1)%(K-1)) return -1;
		if(memo[L][R]>=0) return memo[L][R];
		if(R-L==1) return memo[L][R]=0;
		if(R-L==K) return memo[L][R]=sum[R]-sum[L];
		
		int mi[32][32];
		int x,y;
		FOR(x,31) FOR(y,31) mi[x][y]=1<<29;
		mi[0][L]=0;
		int i,j,k;
		FOR(i,K) {
			for(j=L;j<R;j++) if(mi[i][j]<1<<29) {
				for(k=j+1;k<=R;k++) {
					if(j==L && k==R) continue;
					int ret=dpdp(j,k);
					if(ret>=0) mi[i+1][k]=min(mi[i+1][k],mi[i][j]+ret);
				}
			}
		}
		
		return memo[L][R]=mi[K][R]+sum[R]-sum[L];
		
		
	}
	
    int mergeStones(vector<int>& stones, int K) {
		this->K=K;
		S=stones;
		sum.clear();
		sum.push_back(0);
		FORR(s,S) sum.push_back(sum.back()+s);
		MINUS(memo);
		return dpdp(0,S.size());
    }
};
