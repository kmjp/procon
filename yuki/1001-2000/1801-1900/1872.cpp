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

int N,M;
int A[2020],P[2020];
int can[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>P[i];
	
	bitset<2020> B;
	can[N][0]=1;
	B[0]=1;
	for(i=N-1;i>=0;i--) {
		for(x=A[i];x<=M;x++) if(B[x-A[i]]) can[i][x]=1;
		B|=B<<A[i];
	}
	
	vector<int> V;
	int pre=-1;
	while(M) {
		int best=-1;
		for(i=pre+1;i<N;i++) if(can[i][M]) {
			if(best==-1||P[best]>P[i]) best=i;
		}
		if(best==-1) break;
		M-=A[best];
		V.push_back(best+1);
		pre=best;
	}
	
	if(M) {
		cout<<-1<<endl;
	}
	else {
		cout<<V.size()<<endl;
		FORR(v,V) cout<<v<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}