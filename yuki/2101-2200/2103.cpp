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

ll X,Y,K,P;

void alice() {
	cout<<"Alice"<<endl;
	exit(0);
}
void bob() {
	cout<<"Bob"<<endl;
	exit(0);
}

int dp[101][101][2];
ll win(int x,int y,int turn) {
	if(x+y==K) {
		return (y%2==P)^turn;
	}
	if(dp[x][y][turn]>=0) return dp[x][y][turn];
	
	if(x&&win(x-1,y,turn^1)==0) return dp[x][y][turn]=1;
	if(y&&win(x,y-1,turn^1)==0) return dp[x][y][turn]=1;
	return dp[x][y][turn]=0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>K>>P;
	MINUS(dp);
	
	P=(P==-1);
	
	
	if(K%2==0&&P==0) {
		if(abs(X-Y)%2==0&&abs(X-Y)<K) {
			bob();
		}
		else {
			alice();
		}
	}
	if(K%2==0&&P==1) {
		
		if(abs(X-Y)%2==1&&abs(X-Y)<=K) {
			alice();
		}
		else {
			bob();
		}
	}
	if(K%2==1&&P==0) {
		//FOR(x,30) FOR(y,30) if(x+y>=K&&win(x,y,0)==0) cout<<x<<" "<<y<<" "<<win(x,y,0)<<endl;
		if(abs(X-Y)%2==1&&abs(X-Y)<K||Y-X>=K) {
			bob();
		}
		else {
			alice();
		}
	}
	if(K%2==1&&P==1) {
		if(abs(X-Y)%2==0&&abs(X-Y)<K||Y-X>=K) {
			alice();
		}
		else {
			bob();
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
