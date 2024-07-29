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
vector<int> E[202020];
string S;

int P[200005],D[202020];
int L[202020],re[202020];
int id;
int C[101010];
int dif[101010];

vector<int> tar[101010];
int K;

void dfs(int cur) {
	FORR(e,E[cur]) if(e!=P[cur]) D[e]=D[cur]+1, P[e]=cur, dfs(e);
	L[cur]=id++;
	re[L[cur]]=cur;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<N;i++) {
		cin>>x;
		E[x-1].push_back(i);
	}
	cin>>S;
	dfs(0);
	for(i=1;i<N;i++) C[i]=S[i-1]=='#';
	
	cin>>K;
	FOR(i,K) {
		cin>>x>>y;
		x--,y--;
		if(L[x]>L[y]) swap(x,y);
		tar[x].push_back(y);
	}
	FOR(i,N-1) {
		x=re[i];
		vector<pair<int,int>> T;
		FORR(e,tar[x]) T.push_back({L[e],e});
		sort(ALL(T));
		T.erase(unique(ALL(T)),T.end());
		
		if(T.size()>1) {
			FOR(j,T.size()-1) {
				tar[T[j].second].push_back(T[j+1].second);
			}
		}
		if(dif[x]!=C[x]) {
			if(T.empty()) {
				cout<<"No"<<endl;
				return;
			}
			y=T[0].second;
			dif[x]^=1;
			dif[y]^=1;
		}
		dif[P[x]]^=dif[x];
		
	}
	cout<<"Yes"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
