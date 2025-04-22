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
int A[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int cur=1;
	int X=0,Y=N-1;
	while(Y-X>=2) {
		A[X][X]=cur++;
		int dir=0;
		for(i=X+1;i<=Y;i++) {
			if(dir==0) {
				A[i][X]=cur++;
				A[X][i]=cur++;
			}
			else {
				A[X][i]=cur++;
				A[i][X]=cur++;
			}
			dir^=1;
		}
		dir^=1;
		for(i=X+1;i<Y;i++) {
			if(dir==0) {
				A[i][Y]=cur++;
				A[Y][i]=cur++;
			}
			else {
				A[Y][i]=cur++;
				A[i][Y]=cur++;
			}
			dir^=1;
		}
		A[Y][Y]=cur++;
		X++;
		Y--;
	}
	if(X==Y) A[X][X]=cur;
	else {
		A[X][X]=cur++;
		A[X][X+1]=cur++;
		A[X+1][X]=cur++;
		A[X+1][X+1]=cur++;
	}
	
	
	FOR(y,N) {
		FOR(x,N) cout<<A[y][x]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
