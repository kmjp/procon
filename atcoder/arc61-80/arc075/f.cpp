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

ll D;

ll hoge(ll A,ll t,int first) {
	if(t==0) return A==0;
	int v=(A%10+10)%10;
	ll ret=0;
	ret+=(10-v-first)*hoge((A-t*v)/10,t/100,0);
	ret+=(v-first)*hoge((A+(10-v)*t)/10,t/100,0);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D;
	if(D%9) return _P("0\n");
	D/=9;
	ll ret=0;
	ll p10=10;
	for(i=2;i<=18;i++) {
		p10*=10;
		
		ll tot=(i%2)?10:1;
		ret += tot*hoge(D,p10/10/9,1);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
