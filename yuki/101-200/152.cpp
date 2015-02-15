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

ll L;
ll mo=10000003;
set<ll> S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L;
	L/=4;
	for(x=2;x*x<=L;x++) {
		for(y=1;y<x;y++) {
			ll a=x*x+y*y;
			ll b=x*x-y*y;
			ll c=2*x*y;
			if(b<c) swap(b,c);
			if(a+b+c>L) break;
			ll g=__gcd(a,__gcd(b,c));
			a/=g;
			b/=g;
			c/=g;
			S.insert((a<<40)+(b<<20)+c);
		}
	}
	
	cout<<S.size()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
