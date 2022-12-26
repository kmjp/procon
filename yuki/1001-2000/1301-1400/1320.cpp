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

int T;
int N,M;
vector<pair<int,int>> E[2020];
int U[2020],V[2020],W[2020];
ll D[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		U[i]--;
		V[i]--;
	}
	ll ret=1LL<<60;
	FOR(i,M) {
		FOR(j,N) {
			D[j]=1LL<<60;
			E[j].clear();
		}
		FOR(j,M) if(i!=j) {
			if(T==0) {
				E[U[j]].push_back({V[j],W[j]});
				E[V[j]].push_back({U[j],W[j]});
			}
			else {
				E[U[j]].push_back({V[j],W[j]});
			}
		}
		D[V[i]]=0;
		priority_queue<pair<ll,int>> Q;
		Q.push({0,V[i]});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(D[cur]!=co) continue;
			FORR(e,E[cur]) if(D[e.first]>co+e.second) {
				D[e.first]=co+e.second;
				Q.push({-D[e.first],e.first});
			}
		}
		ret=min(ret,W[i]+D[U[i]]);
	}
	if(ret>=1LL<<60) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
