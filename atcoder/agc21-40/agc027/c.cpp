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

int N,M,lef;
string S;
set<int> E[202020];
int A[202020],B[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	
	set<int> Q;
	FOR(i,N) {
		FORR(e,E[i]) {
			if(S[e]=='A') A[i]++;
			if(S[e]=='B') B[i]++;
		}
		if(A[i]==0 || B[i]==0) Q.insert(i);
	}
	
	lef=N;
	while(Q.size()) {
		x=*Q.begin();
		Q.erase(Q.begin());
		lef--;
		FORR(e,E[x]) if(e!=x) {
			E[e].erase(x);
			if(S[x]=='A') A[e]--;
			if(S[x]=='B') B[e]--;
			if(A[e]==0 || B[e]==0) Q.insert(e);
		}
	}
	if(lef) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
