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

int nex[10][10][10][62];
int A,B,C;
ll K;

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>A>>B>>C>>K;
	A%=10;
	B%=10;
	C%=10;
	FOR(x,10) FOR(y,10) FOR(z,10) {
		int k=(x+y+z)%10;
		nex[x][y][z][0]=y*100+z*10+k;
	}
	K-=3;
	FOR(i,60) {
		FOR(x,10) FOR(y,10) FOR(z,10) {
			int a=nex[x][y][z][i]/100;
			int b=nex[x][y][z][i]/10%10;
			int c=nex[x][y][z][i]%10;
			nex[x][y][z][i+1]=nex[a][b][c][i];
		}
		if(K&(1LL<<i)) {
			int a=nex[A][B][C][i]/100;
			int b=nex[A][B][C][i]/10%10;
			int c=nex[A][B][C][i]%10;
			A=a,B=b,C=c;
		}
	}
	cout<<C<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
