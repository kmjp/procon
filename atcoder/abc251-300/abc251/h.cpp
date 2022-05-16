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

int N,M,K;
vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y;
		V.push_back({x,y});
	}
	
	while(N>K) {
		ll v=1;
		while(N-v*7>=K) v*=7;
		N-=v;
		ll LS=0,LP=0;
		ll RS=0,RP=0;
		vector<pair<int,int>> V2;
		while(V[RS].second<=v) {
			v-=V[RS].second;
			RS++;
		}
		RP=v;
		while(RS<V.size()) {
			int lf=V[LS].second-LP;
			int rf=V[RS].second-RP;
			int nl=min(lf,rf);
			int nv=(V[LS].first+V[RS].first)%7;
			if(V2.empty()||V2.back().first!=nv) {
				V2.push_back({nv,nl});
			}
			else {
				V2.back().second+=nl;
			}
			LP+=nl;
			RP+=nl;
			if(V[LS].second==LP) LS++, LP=0;
			if(V[RS].second==RP) RS++, RP=0;
		}
		
		V=V2;
		
	}
	FORR2(a,b,V) {
		FOR(i,b) cout<<a<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
