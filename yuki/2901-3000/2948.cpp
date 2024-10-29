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

int N,M,K;
int start;
int E[15];
int ok[1<<15][15];
int ok2[15];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,K) {
		cin>>x;
		start|=1<<(x-1);
	}
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x]|=1<<y;
		E[y]|=1<<x;
	}
	FOR(i,N) {
		ZERO(ok);
		ZERO(ok2);
		ok[1<<i][i]=1;
		ok2[1]=1<<i;
		int mask;
		FOR(mask,1<<N) FOR(x,N) if(ok[mask][x]) {
			ok2[__builtin_popcount(mask)]|=1<<x;
			FOR(y,N) if((mask&(1<<y))==0&&(E[x]&(1<<y))) ok[mask|(1<<y)][y]=1;
		}
		FOR(j,N) if((ok2[j]&start)==start) {
			cout<<"Yes"<<endl;
			return;
		}
	}
	
	
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
