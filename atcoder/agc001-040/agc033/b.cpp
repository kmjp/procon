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

int H,W,N;
string S,T;
int Y,X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N>>Y>>X>>S>>T;
	Y--,X--;
	
	int L=0,R=W-1,U=0,D=H-1;
	for(i=N-1;i>=0;i--) {
		if(T[i]=='U') D=min(D+1,H-1);
		if(T[i]=='D') U=max(U-1,0);
		if(T[i]=='L') R=min(R+1,W-1);
		if(T[i]=='R') L=max(L-1,0);
		if(S[i]=='U') U++;
		if(S[i]=='D') D--;
		if(S[i]=='L') L++;
		if(S[i]=='R') R--;
		if(R<L || D<U) return _P("NO\n");
	}
	
	if(X<L || X>R || Y<U || Y>D) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
