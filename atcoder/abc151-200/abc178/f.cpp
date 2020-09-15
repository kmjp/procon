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

int N;
int A[202020],B[202020];
int NA[202020],NB[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		NA[A[i]]++;
	}
	FOR(i,N) {
		cin>>B[i];
		NB[B[i]]++;
	}
	
	int ma=0;
	for(i=1;i<=N;i++) {
		if(NA[i]+NB[i]>N) return _P("No\n");
		NA[i]+=NA[i-1];
		NB[i]+=NB[i-1];
		ma=max(ma,NA[i]-NB[i-1]);
	}
	
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<B[(i+N-ma)%N]<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
