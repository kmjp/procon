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

int T,N,Q;
vector<int> V;
int vis[2][1<<22];

int ret;

void add(int v,int id) {
	if(vis[id][v]) return;
	queue<int> Q;
	vis[id][v]=1;
	Q.push(v);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		if(vis[0][cur]&&vis[1][cur]) ret=max(ret,cur);
		int i;
		FOR(i,22) if(cur&(1<<i)) {
			int ncur=cur^(1<<i);
			if(vis[id][ncur]==0) {
				vis[id][ncur]=1;
				Q.push(ncur);
			}
		}
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		int M=1,L=0;
		while(M<N) M*=2,L++;
		FOR(i,M) vis[0][i]=vis[1][i]=0;
		
		ret=0;
		while(Q--) {
			cin>>x;
			x=(x+ret)%N;
			add(x,0);
			add(x^(M-1),1);
			cout<<ret<<" ";
		}
		cout<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
