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

int T,N;
ll A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<ll,ll>> V={{1,-1LL<<40}};
		FOR(i,N) {
			cin>>A[i];
			pair<ll,ll> P={1,A[i]};
			while(V.back().first*P.second<=V.back().second*P.first) {
				P.second+=V.back().second;
				P.first+=V.back().first;
				V.pop_back();
			}
			V.push_back(P);
		}
		V.erase(V.begin());
		ll ma=-1,mi=1LL<<60;
		FORR2(a,b,V) {
			mi=min(mi,b/a);
			if(b%a==0) {
				ma=max(ma,b/a);
			}
			else {
				ma=max(ma,b/a+1);
			}
		}
		
		cout<<ma-mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
