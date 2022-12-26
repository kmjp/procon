#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N;

map<ll,int> enumdiv(ll n) {
	map<ll,int> V;
	if(n==1) V[1]=1;
	else {
		for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
		if(n>1) V[n]++;
	}
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	map<ll,int> M=enumdiv(N);
	x=0;
	ITR(it,M) x^=it->second;
	if(x==0) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
