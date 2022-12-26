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

int N,Q;
ll D[505050];
ll X[505050];

ll calc(ll tim, int id) {
	return tim/X[id]*X[id]-id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	X[0]=1;
	FOR(i,N) {
		cin>>D[i+1];
		X[i+1]=X[i]*((D[i+1]+X[i]-1)/X[i]);
	}
	while(Q--) {
		ll T,L,R;
		cin>>T>>L>>R;
		int l,r;
		if(calc(T,0)<L) {
			cout<<0<<endl;
			continue;
		}
		if(calc(T,N)>R) {
			cout<<0<<endl;
			continue;
		}
		l=0;
		r=N;
		for(i=20;i>=0;i--) {
			// Là»è„ÇÃç≈ç∂
			if(l+(1<<i)<=N && calc(T,l+(1<<i))>=L) l+=1<<i;
			// Rà»â∫ÇÃÇ‡Ç¡Ç∆âE
			if(r-(1<<i)>=0 && calc(T,r-(1<<i))<=R) r-=1<<i;
		}
		cout<<l-r+1<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
