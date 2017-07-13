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

int X;
int memo[100000][2];

int num0(int v) {
	int num=0;
	if(v==0) return 1;
	if(v>=100000) return memo[v%100000][1]+memo[v/100000][0];
	return memo[v][0];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,100000) {
		j=i;
		FOR(x,5) {
			memo[i][1]+=(j&1)==0;
			j/=10;
		}
		j=i;
		while(j) {
			memo[i][0]+=(j&1)==0;
			j/=10;
		}
	}
	
	cin>>X;
	
	x=num0(X);
	if(x==0) return _P("-1\n");
	
	int L,R;
	for(R=X;num0(R)>=x;R++);
	for(L=X;L>=0&&num0(L)>=x;L--);
	cout<<1LL*(R-X)*(X-L)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
