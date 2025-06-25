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
ll N,W;
vector<ll> V[62];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>W;
		FOR(i,62) V[i].clear();
		FOR(i,N) {
			cin>>x>>y;
			V[x].push_back(y);
		}
		ll ret=0;
		FOR(i,61) {
			sort(ALL(V[i]));
			if((W&(1LL<<i))&&V[i].size()) {
				ret+=V[i].back();
				V[i].pop_back();
			}
			reverse(ALL(V[i]));
			V[i].push_back(0);
			V[i].push_back(0);
			V[i].push_back(0);
			FOR(j,V[i].size()/2) V[i+1].push_back(V[i][j*2]+V[i][j*2+1]);
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
