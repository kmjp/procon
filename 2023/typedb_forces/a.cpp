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
ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<ll,pair<int,int>> M;
	for(x=2;x<=50;x++) {
		ll v=1;
		for(y=1;y<=x;y++) {
			ll x2=1,y2=1;
			FOR(i,y) {
				x2*=x;
				if(x2>1000000000) break;
			}
			FOR(i,x) {
				y2*=y;
				if(y2>1000000000) break;
			}
			if(x2<=1000000000&&y2<=1000000000) {
				ll v=x2*y+y2*x;
				M[v]={x2,y2};
			}
		}
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		if(N%2==0) {
			cout<<1<<" "<<N/2<<endl;
		}
		else if(M.count(N)) {
			cout<<M[N].first<<" "<<M[N].second<<endl;
		}
		else {
			cout<<-1<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
