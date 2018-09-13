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

ll ret;
int N;

ll num(ll n) {
	int d=1;
	ll c=1;
	while(c*10<n) {
		d++;
		c*=10;
	}
	
	return d*c;
}

ll dodo(ll n) {
	ll c=1;
	if(n<=0) return 0;
	if(n<=9) return 1;
	while(c*10<=n) c*=10;
	
	ll ret=0;
	for(ll i=0;i<=9;i++) {
		if(((i+1)*c)>n) {
			if(i==1) ret+=(n-c+1);
			ret+=dodo(n-c*i);
			break;
		}
		else {
			ret += num(c);
			if(i==1) ret+=c;
		}
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cout<<dodo(N)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
