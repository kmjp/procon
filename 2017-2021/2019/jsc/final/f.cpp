#include <bits/stdc++.h>
using namespace std;
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

int N,Q;
int A[2020];
int L[2020],R[2020];
ll fact[2020];
const ll mo=998244353;

vector<pair<int,int>> ev[100];
ll dp[2020];
ll ret[2020];

void divp(int c) {
	int i;
	if(c==0) return;
	FOR(i,N) if(dp[i]) (dp[i+1]=dp[i+1]-dp[i]*c%mo+mo)%=mo;
}

void mulp(int c) {
	int i;
	if(c==0) return;
	for(i=N-1;i>=0;i--) if(dp[i]) (dp[i+1]+=dp[i]*c)%=mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	FOR(i,2010) fact[i+1]=fact[i]*(i+1)%mo;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
	}
	
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		ev[L[i]/45].push_back({R[i],i});
	}
	
	FOR(i,46) if(ev[i].size()) {
		int CL=45*i,CR=CL;
		int cnt[2020]={};
		ZERO(dp);
		dp[0]=1;
		sort(ALL(ev[i]));
		FORR(e,ev[i]) {
			while(CR<e.first) {
				divp(cnt[A[CR]]);
				cnt[A[CR]]++;
				mulp(cnt[A[CR]]);
				CR++;
			}
			while(L[e.second]<CL) {
				CL--;
				divp(cnt[A[CL]]);
				cnt[A[CL]]++;
				mulp(cnt[A[CL]]);
			}
			
			while(CL<L[e.second]) {
				divp(cnt[A[CL]]);
				cnt[A[CL]]--;
				mulp(cnt[A[CL]]);
				CL++;
			}
			
			FOR(j,N+1) {
				if(j&1) {
					(ret[e.second]-=fact[N-j]*dp[j])%=mo;
				}
				else {
					(ret[e.second]+=fact[N-j]*dp[j])%=mo;
				}
			}
		}
	}
	
	FOR(i,Q) cout<<(ret[i]%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
