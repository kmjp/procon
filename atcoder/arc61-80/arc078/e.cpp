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

int ask(ll v) {
	string S;
	cout<<"? "<<v<<endl;
	cin>>S;
	return S[0]=='Y';
}

void ans(ll v) {
	cout<<"! "<<v<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll p10=10000000000LL;
	for(i=10;i>=1;i--) {
		if(ask(p10)==1) break;
		p10/=10;
	}
	
	if(i==10) {
		p10=10000000000LL;;
		for(i=10;i>=1;i--) {
			if(ask(p10-1)==0) ans(p10);
			p10/=10;
		}
	}
	if(i==0) {
		for(i=10;i<=90;i+=10) {
			if(ask(i)==1) ans(i/10);
		}
	}
	ll ret=0,cm=0;
	for(;p10>=1;p10/=10) {
		int cur=-1;
		int dd[4]={8,4,2,1};
		FOR(j,4) if(cur+dd[j]<10) {
			ll tmp=ret+(cur+dd[j])*p10;
			ll tmp2=cm*10+(cur+dd[j]);
			if(ask(tmp2*1000000000LL)==0) cur+=dd[j];
		}
		cm=cm*10+cur;
		ret+=p10*cur;
	}
	
	
	ans(ret+1);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
