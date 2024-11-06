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
ll A[101010],B[101010],C[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<int,int>> D[3];
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		FOR(i,N) cin>>C[i];
		FOR(i,N) {
			D[0].push_back({A[i],i});
			D[1].push_back({B[i],i});
			D[2].push_back({C[i],i});
		}
		FOR(i,3) {
			sort(ALL(D[i]));
			reverse(ALL(D[i]));
			if(D[i].size()>=10) D[i].resize(10);
		}
		int ma=0;
		FORR2(a1,a2,D[0]) FORR2(b1,b2,D[1]) FORR2(c1,c2,D[2]) {
			if(a2==b2) continue;
			if(a2==c2) continue;
			if(c2==b2) continue;
			ma=max(ma,a1+b1+c1);
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
