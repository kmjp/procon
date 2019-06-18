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
ll W[10][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	W[1][0]=W[0][1]=1;
	for(N=3;N<=10;N++) {
		vector<int> V;
		FOR(i,N-1) V.push_back(i);
		ll ma=0;
		do {
			if(V[0]>V.back()) continue;
			ll ret=0;
			FOR(i,N-2) ret+=W[V[i]][V[i+1]];
			ma=max(ma,ret);
		} while(next_permutation(ALL(V)));
		
		ma++;
		int cand[]={1,2,4,7,12,20,29,38,52,73};
		FOR(x,N-1) {
			W[N-1][x]=W[x][N-1]=ma*cand[x];
		}
	}
	
	cin>>N;
	vector<int> V;
	FOR(i,N) V.push_back(i);
	set<ll> C;
	
	do {
		if(V[0]>V.back()) continue;
		ll ret=0;
		FOR(i,N-1) ret+=W[V[i]][V[i+1]];
		assert(C.count(ret)==0);
		
	} while(next_permutation(ALL(V)));
	
	
	FOR(y,N) {
		FOR(x,N) cout<<W[y][x]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
