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

int N;
ll A[1505050];
ll S[1505050];

ll ma[1505050][20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1<<20) A[i]=1LL<<60;
	FOR(i,N) cin>>A[i+1];
	FOR(i,N+2) {
		S[i]=A[i];
		if(i) S[i]+=S[i-1];
		ma[i][0]=A[i];
	}
	FOR(j,19) {
		FOR(i,1<<20) ma[i][j+1]=1LL<<60;
		FOR(i,N+2) ma[i][j+1]=max(ma[i][j],ma[i+(1<<j)][j]);
	}
	
	
	
	for(i=1;i<=N;i++) {
		int L=i,R=i;
		while(1) {
			ll s=S[R]-S[L-1];
			int TR=R,TL=L;
			for(j=19;j>=0;j--) {
				if(TL-(1<<j)>=0&&ma[TL-(1<<j)][j]<s) TL-=(1<<j);
				if(ma[TR+1][j]<s) TR+=1<<j;
			}
			if(TR==R&&TL==L) break;
			L=TL;
			R=TR;
		}
		cout<<S[R]-S[L-1]<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
