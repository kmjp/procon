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
ll D,K;
vector<ll> V[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D>>K;
	FOR(i,N) {
		ll a;
		cin>>x>>a;
		V[x-1].push_back(a);
	}
	sort(ALL(V[0]));
	sort(ALL(V[1]));
	
	if(V[0].empty()) return _P("%d\n",(int)V[1].size());
	if(V[1].empty()) return _P("%d\n",(int)V[0].size());
	
	x=y=0;
	for(i=1;i<=N+1;i++) {
		int nx=V[0].size(),ny=V[1].size();
		
		nx=min(nx,x+1);
		ny=min(ny,y+1);
		if(x<V[0].size()) {
			j=lower_bound(ALL(V[1]),V[0][x]+1+D+i*K)-V[1].begin();
			ny=min(ny,j);
		}
		if(y<V[1].size()) {
			j=lower_bound(ALL(V[0]),V[1][y]+1+D+i*K)-V[0].begin();
			nx=min(nx,j);
		}
		
		
		if(nx==V[0].size()&&ny==V[1].size()) break;
		x=nx;
		y=ny;
	}
	cout<<i<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
