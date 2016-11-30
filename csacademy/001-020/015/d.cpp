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

int T,A,B,K;
ll AA[30],BB[30];

void dodo(int V,ll* R,int K) {
	ll d=1;
	int i,j;
	V++;
	FOR(i,30) {
		R[i]=0;
		if(d>V) continue;
		
		ll lp=V/(d*K),left=V%(d*K);
		R[i]=lp*d*(K*(K-1)/2);
		FOR(j,K) {
			R[i]+=j*min(left,d);
			left-=min(left,d);
		}
		R[i]%=K;
		d*=K;
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>K;
		
		dodo(B,BB,K);
		dodo(A-1,AA,K);
		ll ret=0,order=1;
		FOR(i,30) {
			ret += order * ((BB[i]+K-AA[i])%K);
			order=order*K;
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
