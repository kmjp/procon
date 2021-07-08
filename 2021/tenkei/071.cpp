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

int N,M,K;
vector<int> E[101010];
int in[101010];
deque<int> Q;
vector<int> S;
vector<vector<int>> ret;

void dfs() {
	if(S.size()==N) {
		ret.push_back(S);
		if(ret.size()==K) {
			FORR(r,ret) {
				FORR(v,r) cout<<v<<" ";
				cout<<endl;
			}
			exit(0);
		}
		
		return;
	}
	if(Q.empty()) {
		cout<<-1<<endl;
		exit(0);
	}
	int i;
	FOR(i,Q.size()) {
		int x=Q.front();
		Q.pop_front();
		S.push_back(x);
		FORR(e,E[x]) if(--in[e]==0) Q.push_back(e);
		
		dfs();
		
		FORR(e,E[x]) if(in[e]++==0) Q.pop_back();
		S.pop_back();
		Q.push_back(x);
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		in[y]++;
	}
	
	FOR(i,N) if(in[i+1]==0) Q.push_back(i+1);
	
	dfs();
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
