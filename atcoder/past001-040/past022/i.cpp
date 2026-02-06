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
int Y1,Y2,X1,X2;

vector<int> A[202020],B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Y1>>Y2>>X1>>X2;
	FOR(y,Y2-Y1+1) {
		A[y].resize(X2-X1+1);
		B[y].resize(X2-X1+1);
	}
	FOR(i,N) {
		int Y,X;
		cin>>Y>>X;
		int ty=Y-(X-X1);
		if(ty>=Y1&&ty<=Y2) A[ty-Y1][0]++;
		if(ty<Y1&&Y1-ty<=X2-X1) A[0][Y1-ty]++;
		ty=Y+(X-X1);
		if(ty>=Y1&&ty<=Y2) B[ty-Y1][0]++;
		if(ty>Y2&&ty-Y2<=X2-X1) B[Y2-Y1][ty-Y2]++;
	}
	FOR(x,X2-X1+1) {
		FOR(y,Y2-Y1+1) {
			if(x) {
				if(y) A[y][x]+=A[y-1][x-1];
				if(y+1<Y2-Y1+1) B[y][x]+=B[y+1][x-1];
			}
		}
	}
	FOR(y,Y2-Y1+1) {
		FOR(x,X2-X1+1) {
			if(A[y][x]+B[y][x]) cout<<"#";
			else cout<<".";
		}
		cout<<endl;
	}
		
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
