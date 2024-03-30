#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
string S;
int nex[81][26];
int ma;

int dpdp[81][81];

int lcs(string& AA,string& BB) {
	int x,y,ma=0;
	ZERO(dpdp);
	
	FOR(x,AA.size()) FOR(y,BB.size()) {
		if(AA[x]==BB[y]) dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y]+1);
		dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y+1]);
		dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x+1][y]);
		ma=max(ma,dpdp[x+1][y+1]);
	}
	return ma;
}

void dfs(int cur,string& C) {
	if(cur) {
		int step=C.size();
		int num=0;
		int c=cur;
		while(c<N+1) {
			c=nex[c][C[num]];
			if(c==N+1) break;
			step++;
			num++;
			if(num==C.size()) num=0;
		}
		
		if(step<3*C.size()) return;
		ma=max(ma,(int)(step/C.size()*C.size()));
	}
	int i;
	FOR(i,26) {
		int ne=nex[cur][i];
		if(ne+2*(C.size()+1)<=N&&C.size()+1+(N-ne)>ma) {
			C.push_back(i);
			dfs(ne,C);
			C.pop_back();
		}
		
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FOR(i,N) {
		string a=S.substr(0,i+1);
		string b=S.substr(i+1);
		ma=max(ma,lcs(a,b)*2);
	}
	
	FOR(i,26) nex[N][i]=N+1;
	FORR(c,S) c-='a';
	for(i=N-1;i>=0;i--) {
		FOR(j,26) nex[i][j]=nex[i+1][j];
		nex[i][S[i]]=i+1;
	}
	
	string C;
	dfs(0,C);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
