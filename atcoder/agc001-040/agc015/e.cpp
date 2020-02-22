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

int N;
pair<int,int> P[202020];
int V[202020],L[202020],R[202020];

ll dp[202020];
ll S[202020];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<int,int> M;
	cin>>N;
	FOR(i,N) {
		cin>>P[i].first>>P[i].second;
		M[P[i].second]=0;
	}
	sort(P,P+N);
	x=0;
	FORR(r,M) r.second=++x;
	FOR(i,N) {
		V[i]=M[P[i].second];
		R[i]=max(i?R[i-1]:V[i],V[i]);
	}
	for(i=N-1;i>=0;i--) {
		L[i]=min((i==N-1)?V[i]:L[i+1],V[i]);
	}
	
	dp[0]=S[0]=1;
	y=0;
	FOR(i,N) {
		while(y<R[i]) y++,(S[y]=S[y-1]+dp[y])%=mo;
		ll x=mo+S[R[i]]-((L[i]-2>=0)?S[L[i]-2]:0);
		(dp[R[i]]+=x)%=mo;
		(S[R[i]]+=x)%=mo;
	}
	cout<<dp[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
