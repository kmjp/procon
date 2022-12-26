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

int N,L;
string S;
vector<pair<int,char>> E[2020];
int pre[2020][2020];
int suf[2020][2020];
int ret;

void dfs(int cur,int p) {
	int i,j;
	FORR2(e,c,E[cur]) if(p!=e) {
		dfs(e,cur);
		FOR(i,L) {
			suf[e][i]=max(suf[e][i],(c==S[i])+suf[e][i+1]);
		}
		for(i=L-1;i>=0;i--) suf[e][i]=max(suf[e][i],suf[e][i+1]);
		for(i=L;i>=1;i--) {
			pre[e][i]=max(pre[e][i],(c==S[i-1])+pre[e][i-1]);
		}
		for(i-1;i<=L;i++) pre[e][i]=max(pre[e][i],pre[e][i-1]);
		FOR(i,L+1) {
			suf[cur][i]=max(suf[cur][i],suf[e][i]);
			pre[cur][i]=max(pre[cur][i],pre[e][i]);
		}
	}
	FOR(i,L+1) {
		vector<int> A,B,C;
		A.push_back(0);
		B.push_back(0);
		C.push_back(0);
		A.push_back(0);
		B.push_back(0);
		C.push_back(0);
		FORR2(e,c,E[cur]) if(p!=e) {
			A.push_back(suf[e][i]);
			B.push_back(suf[e][i]);
			C.push_back(pre[e][i]);
		}
		sort(ALL(B));
		reverse(ALL(B));
		FOR(j,A.size()) {
			if(A[j]==B[0]) ret=max(ret,C[j]+B[1]);
			else ret=max(ret,C[j]+B[0]);
		}
		
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	L=S.size();
	FOR(i,N-1) {
		cin>>x>>y>>s;
		E[x-1].push_back({y-1,s[0]});
		E[y-1].push_back({x-1,s[0]});
	}
	
	dfs(0,0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
