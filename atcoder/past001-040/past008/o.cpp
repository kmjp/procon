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
int P[1<<17];
int R[1<<17];
int W[1<<17],L[1<<17];
int cand[18][1<<17];
int fix[18][1<<17];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(cand);
	cin>>N>>M;
	FOR(i,1<<N) {
		cin>>P[i];
		P[i]--;
		R[P[i]]=i;
	}
	FOR(i,M) {
		cin>>W[i]>>L[i];
		W[i]--,L[i]--;
		x=R[W[i]],y=R[L[i]];
		k=0;
		while(x!=y) {
			if(cand[k][x]==-1) cand[k][x]=R[W[i]];
			if(cand[k][y]==-1) cand[k][y]=R[L[i]];
			if(cand[k][x]!=R[W[i]] || cand[k][y]!=R[L[i]]) {
				cout<<0<<endl;
				return;
			}
			fix[k][y]=1;
			k++;
			x/=2;
			y/=2;
		}
		if(cand[k][x]==-1) cand[k][x]=R[W[i]];
		if(cand[k][x]!=R[W[i]]) {
			cout<<0<<endl;
			return;
		}
	}
	int pat=1<<N;
	for(i=N;i>=1;i--) {
		FOR(x,1<<(N-i)) if(cand[i][x]>=0) pat--;
	}
	
	ll ret=1;
	FOR(i,pat) ret=ret*2%mo;
	cout<<ret<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
