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

int V[505][505];
int N,A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	FOR(i,A) {
		int y1,y2,x1,x2;
		cin>>y1>>x1>>y2>>x2;
		y1--,x1--;
		for(y=y1;y<y2;y++) for(x=x1;x<x2;x++) V[y][x]|=1;
	}
	FOR(i,B) {
		int y1,y2,x1,x2;
		cin>>y1>>x1>>y2>>x2;
		y1--,x1--;
		for(y=y1;y<y2;y++) for(x=x1;x<x2;x++) V[y][x]|=2;
	}
	int ret=0;
	FOR(y,N) FOR(x,N) if(V[y][x]==3) ret++;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
