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


int Q;
int N,M,K;

double lfact[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	for(i=2;i<=101000;i++) lfact[i]=lfact[i-1]+log(i);
	
	cin>>Q;
	while(Q--) {
		cin>>N>>M>>K;
		
		double F=0,S=0;
		F=lfact[N]-lfact[K]-lfact[N-K]+log(M);
		S=K*log(M)+log(N-K+1);
		
		if(F<S) cout<<"Flush"<<endl;
		else cout<<"Straight"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
