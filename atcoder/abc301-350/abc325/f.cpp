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
ll D[1011];
ll L[2],C[2],K[2];

ll from[1010];
ll to[1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>D[i];
	FOR(i,2) cin>>L[i]>>C[i]>>K[i];
	FOR(i,1010) from[i]=1010;
	from[0]=0;
	
	FOR(i,N) {
		FOR(j,1010) to[j]=1010;
		FOR(x,K[0]+1) {
			y=max(0LL,(D[i]-x*L[0]+L[1]-1)/L[1]);
			if(y>K[1]) continue;
			for(j=0;j+x<=K[0];j++) to[j+x]=min(to[j+x],from[j]+y);
		}
		
		swap(from,to);
	}
	ll mi=1LL<<60;
	FOR(x,K[0]+1) if(from[x]<=K[1]) mi=min(mi,C[0]*x+C[1]*from[x]);
	if(mi==1LL<<60) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
