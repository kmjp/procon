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

int H,W;
int A[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int nex=1;
	cin>>H>>W;
	
	if(H%2==0) {
		FOR(y,H/2) FOR(x,W) A[y*2+x%2][x]=nex++;
		FOR(y,H/2) FOR(x,W) A[H-1-y*2-(x+W+1)%2][W-1-x]=nex++;
	}
	else if(W%2==0) {
		FOR(x,W/2) FOR(y,H) A[y][x*2+y%2]=nex++;
		FOR(x,W/2) FOR(y,H) A[H-1-y][W-1-x*2-(y+H+1)%2]=nex++;
	}
	else {
		FOR(y,H/2) FOR(x,W) A[y*2+x%2][x]=nex++;
		A[H-1][0]=nex;
		FOR(y,H/2) FOR(x,W) A[H-2-y*2-x%2][W-1-x]=W+nex++;
		int S=A[0][0]+A[0][1]+A[1][0]+A[1][1];
		for(x=1;x<W;x++) A[H-1][x]=S-A[H-1][x-1]-A[H-2][x]-A[H-2][x-1];
	}
	
	cout<<"Yes"<<endl;
	FOR(y,H) {
		FOR(x,W) cout<<A[y][x]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
