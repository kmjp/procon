#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll X,Y;

//‘fˆö”•ª‰ð
vector<ll> enumpr(ll n) {
	vector<ll> V;
	if(n==1) return vector<ll>(1,1);
	for(ll i=2;i*i<=n;i++) while(n%i==0) V.push_back(i),n/=i;
	if(n>1) V.push_back(n);
	sort(V.begin(),V.end());
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X;
	auto v=enumpr(X);
	
	map<ll,int> M;
	FORR(r,v) M[r]++;
	ll ret=1;
	FORR(r,M) if(r.second%2) ret *= r.first;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
