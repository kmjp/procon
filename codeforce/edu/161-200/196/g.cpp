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

int N,M,Q;
vector<int> E[20];
int K[20];

int nex[60][1<<20];
ll T;
int A[20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,N) cin>>K[i];
	FOR(i,M) {
		cin>>x>>y;
		E[y-1].push_back(x-1);
	}
	int mask;
	FOR(mask,1<<N) {
		int nmask=0;
		FOR(i,N) {
			int num=0;
			FORR(e,E[i]) if((mask&(1<<e))==0) num++;
			if(num<K[i]) nmask|=1<<i;
		}
		nex[0][mask]=nmask;
	}
	FOR(i,59) FOR(mask,1<<N) nex[i+1][mask]=nex[i][nex[i][mask]];
	
	while(Q--) {
		cin>>T;
		vector<int> B;
		FOR(i,N) {
			cin>>A[i];
			B.push_back(A[i]);
		}
		sort(ALL(B));
		B.erase(unique(ALL(B)),B.end());
		int C[20]={};
		
		vector<int> Ms;
		for(i=1;i<B.size();i++) {
			int mask=0;
			FOR(j,N) if(A[j]>=B[i]) mask|=1<<j;
			Ms.push_back(mask);
		}
		FOR(j,60) if(T&(1LL<<j)) {
			FORR(m,Ms) m=nex[j][m];
		}
		FORR(m,Ms) FOR(j,N) if(m&(1<<j)) C[j]++;
		
		FOR(i,N) cout<<B[C[i]]<<" ";
		cout<<"\n";
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
