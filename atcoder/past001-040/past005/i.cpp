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
int H[202020];
int D[202020];
vector<pair<int,int>> V;
vector<int> E[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>H[i];
		V.push_back({H[i],i});
		D[i]=1<<20;
	}
	FOR(i,K) {
		cin>>x;
		D[x-1]=0;
	}
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		if(H[x]>H[y]) E[y].push_back(x);
		else E[x].push_back(y);
	}
	
	sort(ALL(V));
	FORR2(a,cur,V) FORR(e,E[cur]) D[e]=min(D[e],D[cur]+1);
	FOR(i,N) {
		if(D[i]==1<<20) D[i]=-1;
		cout<<D[i]<<endl;
	}
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
