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
ll N,X,Y,Z,M;
ll from[101010],to[101010];
ll hoge(ll N,ll V) {
	int i,j;
	if(M<=100000) {
		ZERO(from);
		from[0]=1;
		FOR(i,30) if(N&(1<<i)) {
			int a=(1<<i);
			FOR(j,M) {
				to[j]=from[j]^from[(j+a)%M]^from[((j-a)%M+M)%M];
			}
			swap(from,to);
		}
		return from[V];
	}
	else {
		int ret=0;
		for(ll t=(N+V)%M;t<=2*N;t+=M) {
			int from[2]={1,0};
			FOR(i,40) {
				int to[4]={};
				int b=((t)>>i)&1;
				if(N&(1LL<<i)) {
					
					// not
					to[0]^=from[0];
					to[1]^=from[1];
					// 2^i
					to[1]^=from[0];
					to[2]^=from[1];
					// 2^(i+1)
					to[2]^=from[0];
					to[3]^=from[1];
					
					from[0]=to[b];
					from[1]=to[b|2];
					
				}
				else {
					from[0]=from[b];
					from[1]=0;
				}
			}
			ret^=from[0];
		}
		return ret;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X>>Y>>Z;
		M=X+Y+Z+3;
		int ret=1^hoge(N,X+Y+2)^hoge(N,X+1)^hoge(N,Y+1);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
