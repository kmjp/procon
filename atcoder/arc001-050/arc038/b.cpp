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

int H,W;
string S[1010];
int memo[200][200];

int win(int Y,int X){
	
	int& ret=memo[Y][X];
	if(ret>=0) return ret;
	ret=0;
	
	if(Y<H-1 && S[Y+1][X]=='.' && win(Y+1,X)==0) ret=1;
	if(X<W-1 && S[Y][X+1]=='.' && win(Y,X+1)==0) ret=1;
	if(Y<H-1 && X<W-1 && S[Y+1][X+1]=='.' && win(Y+1,X+1)==0) ret=1;
	
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	if(win(0,0)) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
