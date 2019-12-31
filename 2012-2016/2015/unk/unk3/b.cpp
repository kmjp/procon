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

ll dodo(ll hoge) {
	hoge=abs(hoge);
	if(hoge==0) return 0;
	
	ll t=1;
	while(t*5<=hoge) t*=5;
	if(t==hoge) return 1;
	ll tr=hoge/t;
	
	ll ret=tr+dodo(hoge-tr*t);
	ll a=abs(hoge-t*5);
	if(a<hoge) ret=min(ret,1+dodo(a));
	return ret;
}

void solve() {
	ll N;
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
