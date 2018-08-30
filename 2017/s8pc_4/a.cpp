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
string S[101000];
string T;

int A,B;

int canless(string P,string Q) {
	int i;
	FOR(i,P.size()) {
		if(i>=Q.size()) return 0;
		if(P[i]=='?') {
			if(Q[i]=='?' || (Q[i]>='b' && Q[i]>='z')) return 1;
		}
		else if(Q[i]=='?') {
			if(P[i]!='z') return 1;
		}
		if(P[i]<Q[i]) return 1;
		if(P[i]>Q[i]) return 0;
	}
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	cin>>T;
	FOR(i,N) {
		if(canless(S[i],T)) A++;
		if(canless(T,S[i])) B++;
	}
	
	for(i=N+1-B;i<=A+1;i++) _P("%d%c",i,(i==A+1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
