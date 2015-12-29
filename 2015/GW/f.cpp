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

int N;
int A[51];
int sum,mi=1000;
int memo[3000][51];

int win(int tot,int mi) {
	int& ret=memo[tot][mi];
	if(ret>=0) return ret;
	if(tot==0) return 0;
	ret = 0;
	
	if(tot>mi*N) {
		if(win(tot-1,mi)==0) ret=1;
	}
	if(mi>0) {
		if(win(tot-N,mi-1)==0) ret=1;
		if(win(tot-1,mi-1)==0) ret=1;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i], sum+=A[i], mi=min(mi,A[i]);
	MINUS(memo);
	
	if(win(sum,mi)) cout<<"Iori"<<endl;
	else cout<<"Yayoi"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
