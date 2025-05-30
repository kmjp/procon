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

int T,N,M,X;

int from[1010],to[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>X;
		ZERO(from);
		from[X-1]=1;
		while(M--) {
			cin>>x>>s;
			FOR(i,N) to[i]=0;
			FOR(i,N) if(from[i]) {
				if(s=="0"||s=="?") to[(i+x)%N]=1;
				if(s=="1"||s=="?") to[(i+N-x)%N]=1;
			}
			FOR(i,N) from[i]=to[i];
		}
		int sum=0;
		cout<<count(from,from+N,1)<<endl;
		FOR(i,N) if(from[i]) cout<<i+1<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
