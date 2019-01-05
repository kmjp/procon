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
ll X[101],Y[101],L[101],R[101];

ll dp(int cur) {
	if(cur==0) return 1;
	
	ll LV=dp(L[cur]);
	ll RV=dp(R[cur]);
	
	ll a=X[cur]*LV;
	ll b=Y[cur]*RV;
	ll lcm=a*b/__gcd(a,b);
	return lcm/Y[cur]+lcm/X[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>X[i]>>Y[i]>>L[i]>>R[i];
		ll g=__gcd(X[i],Y[i]);
		X[i]/=g;
		Y[i]/=g;
	}
	ll ma=0;
	for(i=1;i<=N;i++) ma=max(ma,dp(i));
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
