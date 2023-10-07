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
int P[404040],Q[404040],X[404040],Y[404040];
int A[404040];
vector<vector<int>> C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	int nex=0;
	FOR(i,K) {
		cin>>j>>x>>k>>y;
		C[j].push_back({x,k,y});
		C[k].push_back({y,j,x});
		C[j].push_back({x-1,k,y-1});
		C[k].push_back({y-1,j,x-1});
	}
	K=nex;
	queue<int> Q;
	for(i=1;i<=N;i++) {
		A[i]=1;
		Q.push(i);
		sort(ALL(C[i]));
		reverse(ALL(C[i]));
	}
	
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		if(A[cur]>M) {
			cout<<-1<<endl;
			return;
		}
		while(C[cur].size()&&A[cur]>C[cur].back()[0]) {
			x=C[cur].back()[1];
			y=C[cur].back()[2];
			C[cur].pop_back();
			A[x]=max(A[x],y+1);
			Q.push(x);
		}
	}
	ll ret=0;
	for(i=1;i<=N;i++) ret+=A[i];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
