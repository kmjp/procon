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

ll memo[1010][1010];
ll mo=1000000007;

int ri[1010][27];
int le[1010][27];

int N;
string S;

ll hoge(int L,int R) {
	if(memo[L][R]>=0) return memo[L][R];
	
	ll ret=1;
	int i;
	FOR(i,26) if(ri[L][i]<R && le[R][i]>L) {
		ret++;
		if(ri[L][i]<le[R][i]) ret+=hoge(ri[L][i],le[R][i]);
	}
	return memo[L][R]=ret%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	S=(char)('a'+26)+S+(char)('a'+26);
	N=S.size();
	
	MINUS(memo);
	
	FORR(c,S) c-='a';
	FOR(i,27) ri[N-1][i]=N, le[0][i]=-1;
	for(i=N-2;i>=0;i--) {
		FOR(j,27) {
			if(S[i+1]==j) ri[i][j]=i+1;
			else ri[i][j]=ri[i+1][j];
		}
	}
	for(i=1;i<N;i++) {
		FOR(j,27) {
			if(S[i-1]==j) le[i][j]=i-1;
			else le[i][j]=le[i-1][j];
		}
	}
	
	cout<<(hoge(0,N-1)+mo-1)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
