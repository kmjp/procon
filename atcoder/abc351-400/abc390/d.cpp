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
ll A[12];
ll S[1<<12];

vector<ll> V[1<<12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	int mask;
	FOR(mask,1<<N) {
		FOR(i,N) if(mask&(1<<i)) S[mask]+=A[i];
	}
	
	V[(1<<N)-1].push_back(0);
	for(mask=(1<<N)-1;mask>=0;mask--) {
		sort(ALL(V[mask]));
		V[mask].erase(unique(ALL(V[mask])),V[mask].end());
		int ma=0;
		FOR(i,N) if(mask&(1<<i)) ma=1<<i;
		for(int sm=mask;sm>0;sm--) {
			sm=sm&mask;
			if((sm&ma)==0) break;
			FORR(v,V[mask]) V[mask^sm].push_back(v^S[sm]);
		}
	}
	cout<<V[0].size()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
