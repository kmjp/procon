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
string S[55];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		if(S[i][0]=='C') S[i][0]='E';
		if(S[i][1]=='A') S[i][1]='1';
		if(S[i][1]=='T') S[i][1]='A';
		if(S[i][1]=='J') S[i][1]='B';
		if(S[i][1]=='Q') S[i][1]='C';
		if(S[i][1]=='K') S[i][1]='D';
	}
	sort(S,S+N);
	FOR(i,N) {
		if(S[i][0]=='E') S[i][0]='C';
		if(S[i][1]=='A') S[i][1]='T';
		if(S[i][1]=='1') S[i][1]='A';
		if(S[i][1]=='B') S[i][1]='J';
		if(S[i][1]=='C') S[i][1]='Q';
		if(S[i][1]=='D') S[i][1]='K';
		cout<<S[i];
		if(i<N-1) cout<<" ";
	}
	cout<<endl;;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
