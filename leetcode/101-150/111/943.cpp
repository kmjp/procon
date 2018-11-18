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

int same[21][21];
string dp[1<<12][12];

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int x,y,i,mask,j;
        int del[12];

        sort(ALL(A));
        A.erase(unique(ALL(A)),A.end());
        int N=A.size();
        
        ZERO(del);
        FOR(x,N) FOR(y,N) if(A[x].size()<A[y].size()) {
			for(i=0;A[x].size()+i<=A[y].size();i++) {
				if(A[x]==A[y].substr(i,A[x].size())) del[x]=1;
			}
		}
		
		for(i=N-1;i>=0;i--) if(del[i]) A.erase(A.begin()+i);
		N=A.size();
		cout<<N<<endl;
		FOR(i,N) cout<<A[i]<<endl;
        FOR(x,N) FOR(y,N) if(x!=y) {
			int l=0;
			FOR(l,min(A[x].size()+1,A[y].size()+1)) if(A[x].substr(A[x].size()-l)==A[y].substr(0,l)) same[x][y]=l;
		}
		
		FOR(i,N) FOR(mask,1<<N) dp[mask][i]=string(241,'0');
		
		FOR(i,N) dp[1<<i][i]=A[i];
		for(mask=1;mask<1<<N;mask++) {
			FOR(i,N)  if((mask&(1<<i))) {
				FOR(j,N) if((mask&(1<<j))==0) {
					int l=dp[mask][i].size()+(int)A[j].size()-same[i][j];
					if(dp[mask | (1<<j)][j].size() > dp[mask][i].size()+A[j].size()-same[i][j]) {
						dp[mask | (1<<j)][j]=dp[mask][i]+A[j].substr(same[i][j]);
					}
				}
			}
		}
		
		string mi=string(241,'0');
		FOR(i,N) {
			if(mi.size()>dp[(1<<N)-1][i].size()) mi=dp[(1<<N)-1][i];
		}
		return mi;
		
		
		
    }
};
