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

string S,T;
string W[17];
int N;
int A[17];
vector<int> win[17],win2[17];
string ret;

int setchar(int pos,char c) {
	if(S[pos]=='?' || S[pos]==c) {
		T[pos]=c;
		return 1;
	}
	return 0;
}

int dfs(int PL,int PR,int SL,int SR,int win) {
	int tw=win+PR-PL;
	int i;
	for(i=PL;i<=PR;i++) tw-=A[i];
	if(tw) return 0;
	if(PL==PR) {
		W[PL][W[PL].size()-2]=win?'o':'x';
		FOR(i,W[PL].size()) if(setchar(SL+i,W[PL][i])==0) return 0;
		return 1;
	}
	
	if(setchar(SL,'[')==0) return 0;
	if(setchar(SL+1,'(')==0) return 0;
	if(setchar(SR,']')==0) return 0;
	if(setchar(SR-2,')')==0) return 0;
	if(setchar(SR-1,win?'o':'x')==0) return 0;
	
	
	int len=0;
	for(int PM=PL;PM<PR;PM++) {
		len+=W[PM].size();
		int tl=len+5*(PM-PL);
		
		if(dfs(PL,PM,SL+2,SL+2+tl-1,0)&&dfs(PM+1,PR,SL+2+tl,SR-3,win+1)) return 1;
		if(dfs(PL,PM,SL+2,SL+2+tl-1,win+1)&&dfs(PM+1,PR,SL+2+tl,SR-3,0)) return 1;
		
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=16;i++) W[i]="[("+to_string(i)+")o]";
	
	cin>>S>>N;
	S="[("+S+")x]";
	T=S;
	vector<pair<int,int>> V;
	FOR(i,N) {
		cin>>A[i+1];
		V.push_back({i+1,A[i+1]});
	}
	
	dfs(1,N,0,S.size()-1,0);
	cout<<T.substr(2,T.size()-5)<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
