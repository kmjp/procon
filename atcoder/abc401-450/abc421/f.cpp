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

int Q;
vector<int> E[505050];
int P[505050];
int A[505050],B[505050],C[505050];

int pos[505050];

void dfs(int cur,int& p) {
	pos[cur]=p++;
	reverse(ALL(E[cur]));
	FORR(e,E[cur]) dfs(e,p);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(P);
	cin>>Q;
	for(i=1;i<=Q;i++) {
		cin>>A[i];
		if(A[i]==1) {
			cin>>P[i];
			E[P[i]].push_back(i);
		}
		else {
			cin>>B[i]>>C[i];
		}
	}
	
	int cur=0;
	
	dfs(0,cur);
	set<pair<int,int>> S;
	S.insert({0,0});
	for(i=1;i<=Q;i++) {
		if(A[i]==1) {
			S.insert({pos[i],i});
		}
		else {
			x=B[i];
			y=C[i];
			if(pos[x]>pos[y]) swap(x,y);
			ll ret=0;
			auto it=S.lower_bound({pos[x],-1});
			it++;
			while(it->first!=pos[y]) {
				ret+=it->second;
				it=S.erase(it);
			}
			cout<<ret<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
