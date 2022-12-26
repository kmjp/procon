#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N,S,X,Y,Z,T,U,V;
int Q;
ll A[2020000];
ll C[80000];
ll TT[2500];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>X>>Y>>Z;
	
	A[0]=S;
	FOR(i,N) A[i+1]=(X*A[i]+Y)%Z;
	FOR(i,N) C[i/50]|=(A[i]%2)<<(i%50);
	
	cin>>Q;
	while(Q--) {
		cin>>S>>T>>U>>V;
		ll sp=T-S+1;
		S--,U--;
		x=S%50;
		FOR(i,sp/50+2) TT[1+i]=C[S/50+i];
		FOR(i,sp/50+2) TT[1+i]=(TT[1+i]>>x) | (((TT[i+2]&((1LL<<x)-1)))<<(50-x));
		FOR(i,sp/50+4) {
			if((i+1)*50<=sp) continue;
			else if((i+1)*50-sp<=50) TT[i+1]&=(1LL<<(sp%50))-1;
			else TT[i+1]=0;
		}
		x=U%50;
		for(i=sp/50+2;i>=0;i--) TT[i+1]=((TT[i+1]<<x) | (TT[i]>>(50-x))) & ((1LL<<50)-1);
		FOR(i,sp/50+2) C[i+U/50] ^= TT[i+1];
	}
	
	
	FOR(i,N) _P("%c","EO"[(C[i/50]>>(i%50))&1]);
	_P("\n");



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
