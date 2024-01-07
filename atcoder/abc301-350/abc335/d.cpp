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
int A[202][202];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int cx=0,cy=0,cur=1;
	int ON=N;
	while(N>1) {
		FOR(i,N) A[cy][cx+i]=cur++;
		FOR(i,N-1) A[cy+1+i][cx+N-1]=cur++;
		FOR(i,N-1) A[cy+N-1][cx+N-1-1-i]=cur++;
		FOR(i,N-2) A[cy+N-2-i][cx]=cur++;
		N-=2;
		cx++;
		cy++;
	}
	FOR(y,ON) {
		FOR(x,ON) {
			if(A[y][x]==0) cout<<"T ";
			else cout<<A[y][x]<<" ";
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
