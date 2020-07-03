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

int T;
ll K;
ll num[10][10][18];
ll dnum[18];
vector<int> cand[10][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(x,10) FOR(y,10) FOR(r,10) {
		if(x!=r && ((max(x,r)<y)||(min(x,r)>y))) num[x][y][3]++, cand[x][y].push_back(r);
	}
	for(i=4;i<=17;i++) {
		FOR(x,10) FOR(y,10) FOR(r,10) {
			if(x!=r && ((max(x,r)<y)||(min(x,r)>y))) num[x][y][i] += num[y][r][i-1];
		}
	}
	
	for(i=3;i<=17;i++) {
		for(x=1;x<=9;x++) FOR(y,10) dnum[i]+=num[x][y][i];
	}
	
	cin>>T;
	while(T--) {
		cin>>K;
		int d;
		FOR(d,17) {
			if(K<=dnum[d]) break;
			K-=dnum[d];
		}
		for(x=1;x<=9;x++) FOR(y,10) {
			if(K<=num[x][y][d]) goto out;
			K-=num[x][y][d];
		}
		out:
		_P("%d",x);
		d--;
		while(d>=3) {
			FOR(r,10) if(x!=r && ((max(x,r)<y)||(min(x,r)>y))) {
				if(K<=num[y][r][d]) break;
				K-=num[y][r][d];
			}
			x=y;
			_P("%d",x);
			y=r;
			d--;
		}
		_P("%d%d\n",y,cand[x][y][K-1]);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
