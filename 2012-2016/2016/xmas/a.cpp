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

int N;
ll tot;
ll t;
int num[202020];

ll ask(int L,int R) {
	int n=R-L;
	ll ret=0,t;
	if(R==L) return 0;
	
	int x=1;
	while(x*2<=n) x*=2;
	int NL=R-x, NR=L+x;
	
	if(L==0 || num[R-L]<=1+num[NR-NL]) {
		cout<<"? "<<L<<" "<<L+x<<endl;
		cin>>t;
		return t+ask(L+x,R);
	}
	else {
		cout<<"? "<<R-2*x<<" "<<R<<endl;
		cin>>ret;
		return ret - ask(R-2*x,L);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=202000;i++) {
		num[i]=__builtin_popcount(i);
		if(__builtin_popcount(i)>1) {
			x=1;
			while(x<=i) x*=2;
			num[i]=min(num[i],1+__builtin_popcount(i-x));
		}
	}
	
	cin>>N;
	ll ret=ask(0,N);
	cout<<"! "<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
