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
int A[202020],B[202020],C[202020],P[202020];
map<int,ll> ES[202020];
map<int, vector<pair<int,ll>>> E[202020];
map<int,ll> D[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) D[i][0]=1LL<<60;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i]>>P[i];
		A[i]--,B[i]--;
		ES[A[i]][C[i]]+=P[i];
		ES[B[i]][C[i]]+=P[i];
		E[A[i]][C[i]].push_back({B[i],P[i]});
		E[B[i]][C[i]].push_back({A[i],P[i]});
		D[A[i]][C[i]]=D[B[i]][C[i]]=1LL<<60;
	}
	ll ret=1LL<<60;
	
	priority_queue<pair<ll,ll>> Q;
	D[0][0]=0;
	Q.push({0,0});
	while(Q.size()) {
		int cur=Q.top().second/1000000;
		int col=Q.top().second%1000000;
		ll co=-Q.top().first;
		Q.pop();
		if(D[cur][col]!=co) continue;
		if(cur==N-1) continue;
		if(col==0) {
			
			FORR2(col,m,E[cur]) {
				
				if(chmin(D[cur][col],co)) Q.push({-co,cur*1000000LL+col});
				FORR2(t,p,m) {
					ll co2=min(p,ES[cur][col]-p);
					if(t==N-1) {
						ret=min(ret,co+co2);
					}
					//X
					if(chmin(D[t][col],co)) Q.push({-co,t*1000000LL+col});
					//Y
					if(chmin(D[t][0],co+co2)) Q.push({-D[t][0],t*1000000LL});
				}
			}
		}
		else {
			FORR2(t,p,E[cur][col]) {
				ll co2=co+ES[cur][col]-p;
				if(t==N-1) {
					ret=min(ret,co2);
				}
				//Y
				if(chmin(D[t][0],co2)) Q.push({-D[t][0],t*1000000LL});
			}
		}
	}
	
	if(ret<1LL<<60) {
		cout<<ret<<endl;
	}
	else {
		cout<<-1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
