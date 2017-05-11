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

ll N,G;
pair<ll,ll> A[101010];
ll L[101010];
ll S[101010];

bool hoge(pair<ll,ll>& a,pair<ll,ll>& b) {
	return a.second*b.first < b.second*a.first;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>G;
	FOR(i,N) cin>>A[i].first>>A[i].second;
	sort(A,A+N,hoge);
	for(i=N-1;i>=0;i--) S[i]=S[i+1]+A[i].first;
	
	ll tot=0;
	FOR(i,N) {
		G-=A[i].second;
		L[i]=G;
		tot += L[i]*A[i].first;
	}
	ll ma=tot;
	FOR(i,N) {
		ma=max(ma,tot+S[i+1]*A[i].second-L[i]*A[i].first+(L[N-1]+A[i].second)*A[i].first);
	}
	
	ll g=__gcd(ma,N);
	cout<<ma/g<<" "<<N/g<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
