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

string S,T;
int LS,LT;
int memo[1010][1010];

int hoge(int a,int b) {
	if(memo[a][b]>=0) return memo[a][b];
	
	if(a==LS && b==LT) return memo[a][b]=1;
	if(a<LS && b<LT && S[a]==T[b] && hoge(a+1,b+1)) return memo[a][b]=1;
	if(a<LS && S[a]=='A' && hoge(a+1,b)) return memo[a][b]=1;
	if(b<LT && T[b]=='B' && hoge(a,b+1)) return memo[a][b]=1;
	return memo[a][b]=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>S>>T;
	LS=S.size();
	LT=T.size();
	if(hoge(0,0)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
