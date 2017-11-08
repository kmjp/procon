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

int N,M,Q;
ll cand[1010];
string S,T,U;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(1) {
		cin>>N>>M>>Q;
		if(N==0) break;
		FOR(i,M) cand[i]=(1LL<<N)-1;
		S.clear();
		S.resize(M,'0');
		while(Q--) {
			cin>>T>>U;
			ll mask=0;
			FOR(i,N) if(T[i]=='1') mask |= 1LL<<i;
			FOR(i,M) {
				if(S[i]==U[i]) cand[i] &= ~mask;
				else cand[i] &= mask;
			}
			S=U;
		}
		
		FOR(i,M) {
			int id=-1;
			FOR(x,N) {
				if(cand[i] & (1LL<<x)) {
					if(id>=0) {
						_P("?");
						break;
					}
					id=x;
				}
			}
			if(x==N) {
				if(id<10) _P("%d",id);
				else _P("%c",id-10+'A');
			}
		}
		_P("\n");
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
