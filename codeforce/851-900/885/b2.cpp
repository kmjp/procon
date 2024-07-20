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

int T,N,K,C[202020];
vector<int> V[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,K) {
			V[i]={0};
		}
		FOR(i,N) {
			cin>>x;
			V[x-1].push_back(i+1);
		}
		int mi=1<<20;
		FOR(i,K) if(V[i].size()>1) {
			V[i].push_back(N+1);
			vector<int> W;
			FOR(j,V[i].size()-1) W.push_back(V[i][j+1]-V[i][j]-1);
			sort(ALL(W));
			x=W.back();
			W.pop_back();
			W.push_back(x/2);
			sort(ALL(W));
			mi=min(mi,W.back());
		}
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
