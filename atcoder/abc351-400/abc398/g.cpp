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
int vis[202020];
int C[2];
int NE;

int P[4];

void out(int a) {
	if(a) {
		cout<<"Aoki"<<endl;
	}
	else {
		cout<<"Takahashi"<<endl;
	}
	exit(0);
}

void dfs(int cur,int c) {
	if(vis[cur]) return;
	vis[cur]=1;
	C[c]++;
	NE+=E[cur].size();
	FORR(e,E[cur]) dfs(e,c^1);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	ll sum=0;
	FOR(i,N) if(vis[i]==0) {
		ZERO(C);
		NE=0;
		dfs(i,0);
		sum+=1LL*C[0]*C[1]-NE/2;
		if(C[0]+C[1]==1) {
			P[3]++;
		}
		else {
			x=C[0]%2;
			y=C[1]%2;
			P[x+y]++;
		}
	}
	
	if(N%2 || P[1]>=3) {
		out((P[2]+sum)%2);
	}
	else if(P[1]==0) {
		out((P[3]/2+sum)%2);
	}
	else {
		out(1);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
