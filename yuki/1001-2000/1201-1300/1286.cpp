#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll D;

ll dist(ll v,int num) {
	ll sum=0;
	while(num--) {
		sum+=v;
		v/=2;
	}
	return sum;
}

ll hoge(int num) {
	ll ret=1LL<<61;
	for(int i=60;i>=0;i--) {
		if(dist(ret-(1LL<<i),num)>=D) ret-=1LL<<i;
	}
	if(dist(ret,num)==D) return ret;
	return 1LL<<61;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D;
	ll ret=D;
	for(i=1;i<=61;i++) {
		ret=min(ret,hoge(i));
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
