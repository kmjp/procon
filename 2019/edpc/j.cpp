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
double memo[303][303][303];

double dfs(int a1,int a2,int a3) {
	if(a1<0 || a2<0 || a3<0) return 0;
	if(a1+a2+a3==0) return 0;
	if(memo[a1][a2][a3]) return memo[a1][a2][a3];
	
	double step=1.0*N/(a1+a2+a3);
	return memo[a1][a2][a3]=step+(dfs(a1-1,a2,a3)*a1+dfs(a1+1,a2-1,a3)*a2+dfs(a1,a2+1,a3-1)*a3)/(a1+a2+a3);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int cnt[4]={};
	cin>>N;
	FOR(i,N) {
		cin>>x;
		cnt[x]++;
	}
	
	_P("%.12lf\n",dfs(cnt[1],cnt[2],cnt[3]));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
