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
vector<int> cand;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>r>>x>>y;
		j=(1<<(r-1))|(1<<(x-1))|(1<<(y-1));
		cand.push_back(j);
	}
	
	int ma=0;
	int mask;
	FOR(mask,1<<N) {
		int ng=0;
		FORR(c,cand) if((c&mask)==c) ng=1;
		if(ng) continue;
		int r=0;
		FOR(i,N) if((mask&(1<<i))==0) {
			ng=0;
			FORR(c,cand) if((c&(mask|(1<<i)))==c) ng=1;
			r+=ng;
		}
		ma=max(ma,r);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
