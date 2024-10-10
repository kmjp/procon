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
int R[44];

vector<int> V[2][15];
vector<int> W[2][15];

void dfs(int cur,int vis,int num,int rate) {
	if(cur>=N/2) {
		if(num<0) num=-num,rate=-rate;
		V[vis][num].push_back(rate);
		return;
	}
	dfs(cur+1,1,num+1,rate+R[cur]);
	dfs(cur+1,vis,num,rate);
	dfs(cur+1,1,num-1,rate-R[cur]);
}
void dfs2(int cur,int vis,int num,int rate) {
	if(cur<N/2) {
		if(num<0) num=-num,rate=-rate;
		W[vis][num].push_back(rate);
		return;
	}
	dfs2(cur-1,1,num+1,rate+R[cur]);
	dfs2(cur-1,vis,num,rate);
	dfs2(cur-1,1,num-1,rate-R[cur]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>R[i];
	
	if(N>=26) {
		cout<<0<<endl;
		return;
	}
	
	dfs(0,0,0,0);
	dfs2(N-1,0,0,0);
	int ret=1<<30;
	int a,b;
	FOR(i,15) {
		FOR(a,2) FOR(b,2) if(a+b>0) {
			sort(ALL(V[a][i]));
			sort(ALL(W[b][i]));
			V[a][i].erase(unique(ALL(V[a][i])),V[a][i].end());
			W[b][i].erase(unique(ALL(W[b][i])),W[b][i].end());
			reverse(ALL(W[b][i]));
			if(V[a][i].empty()||W[b][i].empty()) continue;
			x=W[b][i].size()-1;
			FORR(v,V[a][i]) {
				while(x>0&&abs(v-W[b][i][x-1])<abs(v-W[b][i][x])) x--;
				for(j=x-2;j<=x+2;j++) if(j>=0&&j<W[b][i].size()) {
					ret=min(ret,abs(v-W[b][i][j]));
				}
			}
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
