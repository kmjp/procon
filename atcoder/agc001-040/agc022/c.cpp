#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[55],B[55];
vector<ll> cand[51][51];
vector<ll> V[51];


void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	
	for(x=0;x<=50;x++) {
		cand[x][x].push_back(0);
		for(y=0;y<x;y++) {
			for(z=1;z<=x;z++) if(x%z>=y) FORR(v,cand[x%z][y]) cand[x][y].push_back(v|(1LL<<z));
			sort(ALL(cand[x][y]));
			cand[x][y].erase(unique(ALL(cand[x][y])),cand[x][y].end());
		}
	}
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>B[i];
		V[i]=cand[A[i]][B[i]];
		if(cand[A[i]][B[i]].empty()) return _P("-1\n");
	}
	
	ll ret=0;
	for(i=50;i>=0;i--) {
		int ng=0;
		FOR(j,N) {
			int ok=0;
			FORR(v,V[j]) if((v&(1LL<<i))==0) ok=1;
			if(ok==0) ng=1;
		}
		if(ng) {
			ret |= 1LL<<i;
		}
		else {
			FOR(j,N) {
				vector<ll> V2;
				FORR(v,V[j]) if((v&(1LL<<i))==0) V2.push_back(v);
				swap(V[j],V2);
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
