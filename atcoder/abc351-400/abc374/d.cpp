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

int mask;
int N;
int S,T;
int X[13],Y[13];
vector<pair<int,pair<int,double>>> E[50];

double dp[13][1<<6];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	FOR(i,N) {
		cin>>X[2*i]>>Y[2*i];
		cin>>X[2*i+1]>>Y[2*i+1];
		E[2*i].push_back({2*i+1,{1<<i,hypot(X[2*i]-X[2*i+1],Y[2*i]-Y[2*i+1])/T}});
		E[2*i+1].push_back({2*i,{1<<i,hypot(X[2*i]-X[2*i+1],Y[2*i]-Y[2*i+1])/T}});
	}
	FOR(x,2*N+1) FOR(y,2*N+1) {
		E[x].push_back({y,{0,hypot(X[x]-X[y],Y[x]-Y[y])/S}});
	}
	FOR(i,13) FOR(mask,1<<6)  dp[i][mask]=1e9;
	dp[2*N][0]=0;
	priority_queue<pair<double,int>> Q;
	Q.push({0.0,2*N*100});
	while(Q.size()) {
		double co=-Q.top().first;
		int cur=Q.top().second/100;
		int mask=Q.top().second%100;
		Q.pop();
		if(mask==(1<<N)-1) {
			_P("%.12lf\n",co);
			return;
		}
		FORR2(e,v,E[cur]) {
			if(chmin(dp[e][mask|v.first],co+v.second)) {
				Q.push({-dp[e][mask|v.first],e*100+(mask|v.first)});
			}
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
