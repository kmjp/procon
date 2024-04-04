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

int T;
int N,M;
string S,L,R;
int nex[303030][10];
int step[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S>>M>>L>>R;
		N=S.size();
		FORR(c,S) c-='0';
		FORR(c,L) c-='0';
		FORR(c,R) c-='0';
		
		FOR(i,10) nex[N][i]=N;
		for(i=N-1;i>=0;i--) {
			FOR(j,10) nex[i][j]=nex[i+1][j];
			nex[i][S[i]]=i;
		}
		FOR(i,N+1) step[i]=M;
		step[0]=0;
		int ok=0;
		FOR(i,N) if(step[i]<M) {
			for(x=L[step[i]];x<=R[step[i]];x++) {
				if(nex[i][x]>=N) ok=1;
				else step[nex[i][x]+1]=min(step[nex[i][x]+1],step[i]+1);
			}
		}
		if(ok||step[N]<M) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
