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

int N;
ll A[101010],S[101010],SM[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
		SM[i+1]=SM[i]+i*A[i];
		
	}
	ll mi=1LL<<60;
	for(i=0;i<N;i+=2) {
		ll lad=i;
		ll rad=(N-1-i);
		lad=lad*(lad-1)/2;
		rad=rad*(rad-1)/2;
		
		ll ltot=i*S[i]-SM[i];
		ll rtot=SM[N]-SM[i+1]-i*(S[N]-S[i+1]);
		
		mi=min(mi,lad+rad+ltot+rtot);
	}
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
