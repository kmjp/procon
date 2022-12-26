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

int N, A[303030];
int R[303030];
int B[303030];
int nex[303030];

vector<pair<int,int>> E[303030];
ll K;
const ll ma=1LL<<61;
ll dp[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	A[0]=0;
	FOR(i,N) cin>>A[i+1];
	A[N+1]=1<<30;
	N+=2;
	
	FOR(i,N+2) R[i]=1+(1<<30);
	FOR(i,N) {
		B[i]=lower_bound(R,R+N+1,A[i])-R;
		R[B[i]]=A[i];
		E[B[i]].push_back({A[i],i});
	}
	FOR(i,N+1) {
		map<int,int> M;
		sort(ALL(E[i]));
		reverse(ALL(E[i]));
		FORR(r,E[i]) {
			x = r.second;
			nex[x]=N;
			if(M.count(A[x])) nex[x]=M[A[x]];
			M[A[x]]=x;
		}
	}
	dp[N-1]=1;
	for(i=B[N-1]-1;i>=0;i--) {
		FORR(r,E[i]) {
			x = r.second;
			FORR(r2,E[i+1]) if(r2.second>x && A[r2.second]>A[x] && r2.second<nex[x]) {
				dp[x] = min(ma,dp[x]+dp[r2.second]);
			}
		}
	}
	
	if(dp[0]<K) return _P("None\n");
	int cur=0;
	FOR(i,B[N-1]) {
		FORR(e,E[i]) {
			if(e.second>cur && nex[e.second]<N) {
				dp[e.second] = min(ma,dp[e.second]+dp[nex[e.second]]);
				dp[nex[e.second]]=0;
			}
		}
		reverse(ALL(E[i]));
		FORR(e,E[i]) {
			x = e.second;
			if(x<cur || A[x]<=A[cur]) continue;
			if(K<=dp[x]) {
				cur=x;
				if(cur) cout<<A[cur]<<" ";
				break;
			}
			else {
				K -= dp[x];
			}
		}
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
