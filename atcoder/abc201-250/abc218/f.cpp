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
int S[202020],T[202020];

vector<pair<int,int>> E[404];


int D[404];
int from[404],fe[404];
int ret[202020];

void go(int inv) {
	int i;
	FOR(i,N) D[i]=1<<20;
	D[0]=0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR2(e,id,E[cur]) if(id!=inv) {
			if(D[e]>D[cur]+1) {
				D[e]=D[cur]+1;
				from[e]=cur;
				fe[e]=id;
				Q.push(e);
			}
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>S[i]>>T[i];
		S[i]--,T[i]--;
		E[S[i]].push_back({T[i],i});
	}
	
	go(-1);
	if(D[N-1]>N) {
		FOR(i,M) cout<<-1<<endl;
		return;
	}
	
	vector<int> cand;
	x=N-1;
	while(x) {
		cand.push_back(fe[x]);
		x=from[x];
	}
	FOR(i,M) {
		ret[i]=D[N-1];
	}
	FORR(c,cand) {
		go(c);
		ret[c]=D[N-1];
		if(ret[c]>N) ret[c]=-1;
	}
	FOR(i,M) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
