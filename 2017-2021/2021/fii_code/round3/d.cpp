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

int N,Q;
int V[101010];
int nex[1010105];
int ne[1010105][20];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>V[i];
	FOR(i,1000005) nex[i]=N;
	int mi=N;
	ne[N][0]=N;
	for(i=N-1;i>=0;i--) {
		ne[i][0]=min(mi,nex[V[i]]);
		mi=min(mi,ne[i][0]);
		nex[V[i]]=i;
	}
	
	FOR(i,19) {
		FOR(j,N+1) ne[j][i+1]=ne[ne[j][i]][i];
	}
	
	cin>>Q;
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--;
		int num=0;
		for(j=18;j>=0;j--) if(ne[L][j]<R) {
			num+=(1<<j);
			L=ne[L][j];
		}
		cout<<num+1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
