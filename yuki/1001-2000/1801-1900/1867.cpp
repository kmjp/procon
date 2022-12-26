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
int P[3030];
int S[3030][3030];
int sum[3030];

int from[3030];
int to[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
	}
	
	FOR(x,N) {
		ZERO(sum);
		FOR(y,x) sum[P[y]]++;
		FOR(y,N+1) if(y) sum[y]+=sum[y-1];
		int pat=0;
		for(y=x;y<N;y++) {
			pat+=sum[N]-sum[P[y]];
			S[x][y+1]=pat;
		}
	}
	
	FOR(i,N+1) from[i]=1<<30;
	from[0]=0;
	for(i=1;i<=N;i++) {
		FOR(j,N+1) to[j]=1<<30;
		for(j=i-1;j<=N-1;j++) {
			for(x=j+1;x<=N;x++) to[x]=min(to[x],from[j]+S[j][x]);
		}
		cout<<to[N]<<endl;
		swap(from,to);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
