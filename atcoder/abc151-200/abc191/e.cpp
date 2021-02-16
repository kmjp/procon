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
vector<pair<int,int>> E[2020];
ll D[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
	}
	FOR(x,N) FOR(y,N) D[x][y]=(x==y?0:1LL<<30);
	FOR(i,N) {
		priority_queue<pair<ll,int>> Q;
		D[i][i]=0;
		Q.push({0,i});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(D[i][cur]!=co) continue;
			FORR2(e,c,E[cur]) if(D[i][e]>co+c) {
				D[i][e]=co+c;
				Q.push({-D[i][e],e});
			}
		}
	}
	FOR(i,N) {
		ll ret=1LL<<30;
		FORR2(e,c,E[i]) if(e==i) ret=min(ret,(ll)c);
		FOR(j,N) if(i!=j) ret=min(ret,D[i][j]+D[j][i]);
		if(ret>=1LL<<30) ret=-1;
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
