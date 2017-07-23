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

int N,M,H,K;
int sw[1010][1010];
int O[1010];
int S[1010],T[1010];

vector<int> ev[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>H>>K;
	
	FOR(i,N) cin>>S[i];
	FOR(i,M) {
		cin>>x>>y;
		ev[y].push_back(x-1);
	}
	
	FOR(i,N) O[i]=i, sw[i][i]=1;
	FOR(i,H) {
		FORR(e,ev[i]) {
			sw[O[e]][O[e+1]]=sw[O[e+1]][O[e]]=1;
			swap(O[e],O[e+1]);
		}
	}
	
	FOR(i,N) T[O[i]]=S[i];
	ll ma=0;
	ll tot=0;
	FOR(i,K) tot+=T[i];
	ma=tot;
	FOR(x,K) for(y=K;y<N;y++) if(sw[x][y]) {
		ma=min(ma,tot-T[x]+T[y]);
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
