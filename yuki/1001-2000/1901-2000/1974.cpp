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

void ans() {
	int y,x;
	int sum=0;
	FOR(y,H) FOR(x,W) sum+=A[y][x];
	cout<<sum<<endl;
	FOR(y,H) {
		FOR(x,W) cout<<A[y][x]<<" ";
		cout<<endl;
	}
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	if(H==1||W==1) ans();
	
	
	if(H%2==0&&W%2==0) {
		FOR(y,H) FOR(x,W) A[y][x]=1;
	}
	else if(H%2&&W%2) {
		FOR(y,H) FOR(x,W) A[y][x]=1;
		FOR(i,max(y,x)) A[min(i,H-1)][min(i,W-1)]=0;
	}
	else {
		FOR(y,(H/2)*2) FOR(x,(W/2)*2) A[y][x]=1;
	}
	
	ans();
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
