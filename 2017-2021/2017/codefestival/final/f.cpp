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

int N,K;

int ret[2020][2020];

void check() {
	int cnt[2020]={};
	int i,j,y,x;
	FOR(y,N) FOR(x,K) cnt[ret[y][x]]++;
	FOR(i,N) if(cnt[i+1]!=K) _P("NG\n");
	FOR(y,N) for(x=1;x<y;x++) {
		int match=0;
		FOR(i,K) FOR(j,K) if(ret[y][i]==ret[x][j]) match++;
		if(match!=1) _P("NG2 %d %d\n",x,y);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	//cin>>K;
	K=38;
	N=K*(K-1)+1;
	
	FOR(x,K) ret[0][x]=x+1;
	for(y=1;y<N;y++) ret[y][0]=1+(y-1)/(K-1);
	int nex=K+1;
	for(y=1;y<K;y++) {
		for(x=1;x<K;x++) {
			ret[y][x]=nex;
			FOR(i,K-1) {
				int y2=K+i*(K-1)+(i*(y-1)+((K-1)*2020)+x-1)%(K-1);
				ret[y2][y]=nex;
			}
			nex++;
		}
	}
	
	check();
	_P("%d %d\n",N,K);
	FOR(y,N) {
		FOR(x,K) _P("%d%c",ret[y][x],(x==(K-1))?'\n':' ');
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
