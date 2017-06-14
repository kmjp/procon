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

map<ll,int> memo;

ll N;

int hoge(ll N) {
	if(N==1) return 0;
	if(N==2) return 1;
	if(N==0) return 101010;
	if(memo.count(N)) return memo[N];
	int ret=0;
	
	if(N%3==0) ret=1+hoge(N/3);
	if(N%3==1) ret=min(1+hoge(N-1),2+hoge(N+2));
	if(N%3==2) ret=min(2+hoge(N-2),1+hoge(N+1));
	
	return memo[N]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cout<<hoge(N)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
