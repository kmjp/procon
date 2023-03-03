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
int A[4][4]={
{7,14,0,8},
{4,12,2,11},
{15,9,6,1},
{13,10,5,3},
};
int C[4][4]={
{0,1,4,5},
{2,3,6,7},
{8,9,12,13},
{10,11,14,15},
};
int B[1024][1024];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	if(N==1) {
		cout<<-1<<endl;
		return;
	}
	int nex=0;
	FOR(y,1<<(N-2)) FOR(x,1<<(N-2)) {
		int y2,x2;
		FOR(y2,4) FOR(x2,4) {
			if(x==y) B[y*4+y2][x*4+x2]=nex+A[y2][x2];
			else B[y*4+y2][x*4+x2]=nex+C[y2][x2];
		}
		nex+=16;
		
	}
	FOR(y,1<<N) {
		FOR(x,1<<N) {
			cout<<B[y][x]<<" ";
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
