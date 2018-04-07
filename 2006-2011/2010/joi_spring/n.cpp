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

int N,M,T,X,Y;
int P[1010];
int S[1010][101];
int miss[1010][101];
ll pt[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>T>>X>>Y;
	FOR(i,M) cin>>P[i];
	FOR(i,Y) {
		int t,n,m;
		cin>>t>>n>>m>>s;
		if(s=="open") {
			S[n-1][m-1]=t;
		}
		if(s=="incorrect") {
			miss[n-1][m-1]++;
		}
		if(s=="correct") {
			pt[n-1] += max(X,P[m-1]-(t-S[n-1][m-1])-120*miss[n-1][m-1]);
		}
	}
	FOR(i,N) cout<<pt[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
