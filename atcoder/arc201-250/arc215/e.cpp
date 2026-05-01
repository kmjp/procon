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

int T,N,M;
string A,B;
int X[202020],Y[202020];
set<pair<int,int>> E[202020];
set<pair<int,int>> RE[202020];
int my[202020];
vector<int> ret;

void dfs(int cur) {
	if(A[cur]=='0'||E[cur].empty()) return;
	auto EE=E[cur];
	E[cur].clear();
	FORR2(e,i,RE[cur]) E[e].erase({cur,i});
	
	FORR2(e,i,EE) {
		dfs(e);
		if(A[e]!=B[e]) {
			ret.push_back(i);
			A[e]=B[e];
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B;
		FOR(i,N) {
			E[i].clear();
			RE[i].clear();
			my[i]=-1;
		}
		cin>>M;
		FOR(i,M) {
			cin>>X[i]>>Y[i];
			X[i]--;
			Y[i]--;
			if(X[i]==Y[i]) {
				my[X[i]]=i;
			}
			else {
				E[X[i]].insert({Y[i],i});
				RE[Y[i]].insert({X[i],i});
			}
		}
		ret.clear();
		queue<int> Q;
		
		FOR(i,N) if(A[i]=='1') Q.push(i);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR2(e,i,E[cur]) if(A[e]=='0') {
				A[e]='1';
				ret.push_back(i);
				Q.push(e);
			}
		}
		FOR(i,N) if(A[i]=='1') {
			if(B[i]=='1'||my[i]!=-1) dfs(i);
			if(B[i]=='0'&&my[i]!=-1) {
				A[i]='0';
				ret.push_back(my[i]);
			}
		}
		
		
		FOR(i,N) if(A[i]!=B[i]) break;
		
		if(i<N) {
			cout<<-1<<endl;
		}
		else {
			cout<<ret.size()<<endl;
			FORR(e,ret) cout<<e+1<<" ";
			cout<<endl;
		}
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
