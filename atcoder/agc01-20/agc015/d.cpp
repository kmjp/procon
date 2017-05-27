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


ll hoge(ll L,ll R) {
	if(L==R) return 1;
	
	ll r=1;
	while(r*2<=R) r*=2;
	
	if(L&r) return hoge(L^r,R^r);
	
	ll k=1;
	while(k<=(R^r)) k*=2;
	
	//only a
	ll ret=r-L;
	
	// only B
	ll x=r,y=r+k-1;
	// A+B
	ll a=r+L,b=2*r-1;
	
	if(y<a) return ret+y-x+1+b-a+1;
	else return ret+b-x+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	ll A,B;
	
	cin>>A>>B;
	cout<<hoge(A,B)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
