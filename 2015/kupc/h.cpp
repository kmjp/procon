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

int T;
ll N;
ll memo[65][65][140][2];

ll dfs(int d,int mi,int dif,int lz) {
	if(d==-1) {
		if(lz==0) return -2;
		if(dif==0) return 0;
		else return -2;
	}
	ll& ret=memo[d][mi][dif+70][lz];
	if(ret==-1) {
		
		if(N&(1LL<<d)) {
			// take zero
			ret=dfs(d-1,mi+1,dif+1,lz);
			if(ret<0) {
				ret=dfs(d-1,0,dif-mi,1);
				if(ret>=0) ret+= 1LL<<d;
			}
		}
		else {
			// take zero
			ret=dfs(d-1,0,dif,lz);
			if(ret<0) {
				ret=dfs(d-1,mi+1,dif,1);
				if(ret>=0) ret+= 1LL<<d;
			}
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>N;
		MINUS(memo);
		cout<<dfs(60,0,0,0)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
