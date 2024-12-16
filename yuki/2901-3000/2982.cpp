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
int A[3];
vector<pair<ll,ll>> from[3];
vector<pair<ll,ll>> to[3];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(j,3) from[j].push_back({0,0});
	FOR(i,N) {
		FOR(j,3) to[j].clear();
		FOR(j,3) {
			cin>>A[j];
			FOR(x,3) if(j!=x) FORR2(a,b,from[x]) to[j].push_back({max(0LL,a+A[j]-1),b+a+A[j]});
		}
		FOR(j,3) {
			from[j].clear();
			sort(ALL(to[j]));
			FORR2(a,b,to[j]) {
				while(from[j].size()&&from[j].back().second<=b) from[j].pop_back();
				from[j].push_back({a,b});
			}
		}
	}
	ll ret=0;
	FOR(j,3) FORR2(a,b,from[j]) ret=max(ret,b);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
