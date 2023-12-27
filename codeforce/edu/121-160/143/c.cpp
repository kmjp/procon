#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N;
ll A[202020],B[202020];
ll SB[202020];
ll num[202020];
ll D[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		FOR(i,N) cin>>A[i];
		FOR(i,N) {
			cin>>B[i];
			SB[i+1]=B[i]+SB[i];
			num[i]=D[i]=0;
		}
		SB[N+1]=SB[N]+1;
		FOR(i,N) {
			x=lower_bound(SB,SB+N+1,SB[i]+A[i])-SB;
			num[i]++;
			num[x-1]--;
			D[x-1]+=A[i]-(SB[x-1]-SB[i]);
		}
		FOR(i,N) {
			if(i) num[i]+=num[i-1];
			cout<<(1LL*num[i]*B[i]+D[i])<<" ";
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
