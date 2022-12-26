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


int N,M;
vector<int> E[202020];
int A[202020],B[202020],C[202020];
int vis[202020];

int hoge(int CA) {
	int CB=1,CC=1;
	ZERO(vis);
	
	//èâéËÇæÇØämîF
	if(CA+CB+CC<=A[0]+B[0]+C[0]) return 0;
	int add=max({0,A[0]-1,B[0]-1,C[0]-1});
	
	int ok=0;
	FORR(e,E[0]) if(CA+CB+CC+add>A[e]+B[e]+C[e]) ok=1;
	if(ok==0) return 0;
	priority_queue<pair<int,int>> Q;
	vis[0]=1;
	Q.push({-A[0]-B[0]-C[0],0});
	while(Q.size()) {
		int cur=Q.top().second;
		Q.pop();
		if(A[cur]+B[cur]+C[cur]>=CA+CB+CC) return 0;
		if(cur==N-1) return 1;
		vector<int> V={CA,CB,CC,A[cur],B[cur],C[cur]};
		sort(ALL(V));
		CA=V[5];
		CB=V[4];
		CC=V[3];
		FORR(e,E[cur]) if(vis[e]==0) {
			Q.push({-A[e]-B[e]-C[e],e});
			vis[e]=1;
		}
	}
	return 0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) cin>>A[i]>>B[i]>>C[i];
	int ret=1<<30;
	for(i=29;i>=0;i--) if(hoge(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<" "<<1<<" "<<1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
