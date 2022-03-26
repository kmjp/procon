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

int N,M,K,L;
int A[101010];
int ok[101010];

vector<pair<int,int>> E[202020];
int C[2][202020];
ll D[2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>L;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		C[0][i]=C[1][i]=K;
		D[0][i]=D[1][i]=1LL<<60;
	}
	priority_queue<pair<ll,int>> Q;
	FOR(i,L) {
		cin>>x;
		x--;
		C[0][x]=A[x];
		D[0][x]=0;
		Q.push({0,x});
	}
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second%N;
		int id=Q.top().second/N;
		Q.pop();
		if(D[id][cur]!=co) continue;
		FORR2(e,c,E[cur]) {
			if(D[0][e]>co+c) {
				if(C[0][e]!=C[id][cur]) {
					C[1][e]=C[0][e];
					D[1][e]=D[0][e];
					Q.push({-D[1][e],e+N});
				}
				D[0][e]=co+c;
				C[0][e]=C[id][cur];
				Q.push({-D[0][e],e});
			}
			else if(D[1][e]>co+c&&C[id][cur]!=C[0][e]) {
				C[1][e]=C[id][cur];
				D[1][e]=co+c;
				Q.push({-D[1][e],e+N});
			}
		}
	}
	
	FOR(i,N) {
		ll a=(A[i]==C[0][i])?D[1][i]:D[0][i];
		if(a>=1LL<<60) a=-1;
		cout<<a<<" ";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
