#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,S,P[40];
map<ll,vector<int> > M[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) cin>>P[i];
	
	if(N<=16) {
		for(int mask=(1<<N)-1;mask>=0;mask--) {
			x=0;
			FOR(y,N) if(mask&(1<<(N-1-y))) x+=P[y];
			if(x==S) {
				i=0;
				FOR(y,N) if(mask&(1<<(N-1-y))) {
					if(i!=0) _P(" ");
					_P("%d",y+1);
					i++;
				}
				_P("\n");
			}
		}
	}
	else {
		for(int mask=(1<<16)-1;mask>=0;mask--) {
			x=0;
			FOR(y,16) if(mask&(1<<y)) x+=P[N-1-y];
			M[0][x].push_back(mask);
		}
		for(int mask=(1<<(N-16))-1;mask>=0;mask--) {
			x=0;
			FOR(y,N-16) if(mask&(1<<y)) x+=P[N-17-y];
			M[1][x].push_back(mask);
		}
		set<ll> SS;
		ITR(it,M[0]) if(M[1].count(S-it->first)) {
			vector<int> V1=it->second;
			vector<int> V2=M[1][S-it->first];
			ITR(it3,V1) ITR(it4,V2) SS.insert(-(((ll)(*it4)<<16)|*it3));
		}
		ITR(it,SS) {
			ll ma=-*it;
			i=0;
			FOR(y,N) if(ma&(1<<(N-1-y))) {
				if(i!=0) _P(" ");
				_P("%d",y+1);
				i++;
			}
			_P("\n");
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
