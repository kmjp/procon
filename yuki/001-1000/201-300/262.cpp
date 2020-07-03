#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll add[51][64];
ll step[51][64];
ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,30) FOR(j,63) if(i+j) {
		int cur=j;
		int st=0;
		while(cur<1<<20) {
			st++;
			cur += i+__builtin_popcount(cur);
		}
		step[i][j]=st;
		add[i][j]=cur-j;
	}
	
	cin>>N;
	ll cur=1;
	ll st=1;
	while(cur+add[__builtin_popcountll(cur>>20)][cur%64]<N) {
		st += step[__builtin_popcountll(cur>>20)][cur%64];
		cur+=add[__builtin_popcountll(cur>>20)][cur%64];
	}
	while(cur<N) {
		st++;
		cur+=__builtin_popcountll(cur);
	}
	if(cur==N) cout<<st<<endl;
	else cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
