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

ll L,S;
ll ret;
set<int> SS[50501];

void dfs(int a,int b,int c,int step) {
	if(a+b+c>L) return;
	
	int x=__gcd(a,b);
	if(x>1 && __gcd(x,c)>1) return;
	
	if(a<=10100) {
		if(SS[a].count(b)) return;
		SS[a].insert(b);
	}
	if(a && a+b>c) ret++;
	
	dfs(1*a-2*b+2*c,2*a-1*b+2*c,2*a-2*b+3*c,step+1);
	if(a<b) dfs(-2*a+1*b+2*c,-1*a+2*b+2*c,-2*a+2*b+3*c,step+1);
	dfs(2*a+1*b+2*c,1*a+2*b+2*c,2*a+2*b+3*c,step+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	int a,b,c,g;
	cin>>L>>S;
	
	for(a=0;a<=2*S;a++) {
		ll d = a*a+S*S;
		for(ll cb=1;cb*cb<d;cb++) if(d % cb==0) {
			ll cb2=d/cb;
			if((cb+cb2)%2) continue;
			c = (cb+cb2)/2;
			b = (cb2-cb)/2;
			dfs(min(a,b),max(a,b),c,0);
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
