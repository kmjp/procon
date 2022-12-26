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
ll D[2020];
int mi=1010;

int tot() {
	int E[12][12];
	int x,y,z;
	FOR(x,N+2) FOR(y,N+2) E[y][x]=(y==x)?0:2000;
	for(x=1;x<=N;x++) {
		for(y=x-1;y>=0;y--) if(D[y]>=D[x]) {
			E[y][x]=E[x][y]=1;
			break;
		}
		for(y=x+1;y<=N+1;y++) if(D[y]>=D[x]) {
			E[y][x]=E[x][y]=1;
			break;
		}
	}
	FOR(z,N+2) FOR(x,N+2) FOR(y,N+2) E[x][y]=min(E[x][y],E[x][z]+E[z][y]);
	int tot=0;
	for(x=1;x<=N;x++) for(y=1;y<=N;y++) tot+=E[y][x];
	return tot;
	
}

void dfs(int mask,int nex) {
	int i;
	if(mask==(1<<N)-1) {
		int x=tot();
		if(x<=mi) {
			mi=x;
			FOR(i,N) cout<<D[i+1]<<" ";
			cout<<mi<<endl;
		}
	}
	int lef=mask^((1<<N)-1);
	for(int sm=lef;sm>0;sm=(sm-1)&lef) {
		FOR(i,N) if(sm&(1<<i)) D[i+1]=nex;
		dfs(mask|sm,nex+1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	D[0]=D[N+1]=2000000000;
	/*
	vector<int> V;
	dfs(0,1);
	FOR(i,N-1) V.push_back(i+1);
	V.push_back(N-1);
	do {
		FOR(i,N) D[i+1]=V[i];
		x=tot();
		if(x<=mi) {
			mi=x;
			FOR(i,N) cout<<D[i+1]<<" ";
			cout<<mi<<endl;
		}
	} while(next_permutation(ALL(V)));
	*/
	for(i=2;i<=N-1;i++) D[i]=5+i-1;
	D[1]=5+N-1;
	D[N]=5+N;
	FOR(i,N+2) {
		if(i) cout<<" ";
		cout<<D[i];
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
