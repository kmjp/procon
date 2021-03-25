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
int H[2020];
pair<int,int> P[2020];
int order[2020];
vector<int> E[2020];
int K;
int V[2][2020];

int nex[2020],dif[2020];
ll D[2020];

void dfs(int cur,int pre,int ma) {
	ma=max(ma,H[cur]);
	D[cur]=ma;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,ma);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>H[i];
	
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	FOR(i,N) {
		dfs(i,i,0);
		D[i]=1<<30;
		nex[i]=i;
		FOR(j,N) if(H[j]<H[i]||(H[j]==H[i]&&j<i)) {
			if(D[j]<D[nex[i]]) nex[i]=j;
		}
		dif[i]=D[nex[i]]-H[i];
	}
	
	cin>>K;
	ll P[2]={};
	ll ma;
	int same=0;
	priority_queue<pair<int,int>> Q;
	FOR(i,K) {
		cin>>V[0][i]>>V[1][i];
		V[0][i]--,V[1][i]--;
		P[0]+=H[V[0][i]];
		P[1]+=H[V[1][i]];
		if(V[0][i]==V[1][i]) same++;
		Q.push({-dif[V[0][i]],i*2});
		Q.push({-dif[V[1][i]],i*2+1});
	}
	ma=max(P[0],P[1]);
	while(same<K) {
		int cur=Q.top().second/2;
		int id=Q.top().second%2;
		Q.pop();
		
		if(V[0][cur]==V[1][cur]) same--;
		
		ma=max(ma,P[id]+dif[V[id][cur]]);
		P[id]-=H[V[id][cur]]-H[nex[V[id][cur]]];
		V[id][cur]=nex[V[id][cur]];
		Q.push({-dif[V[id][cur]],cur*2+id});
		
		if(V[0][cur]==V[1][cur]) same++;
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
