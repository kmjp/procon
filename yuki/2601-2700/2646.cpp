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


int pat[10][606];
int H,W,T;
int SY,SX,GY,GX;
int A[202][202];
int from[202][202],to[202][202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,10) FOR(j,606) pat[i][j]=((i-j)%(i+1)+(i+1))%(i+1)>0;
	
	cin>>H>>W>>T;
	cin>>SY>>SX;
	cin>>GY>>GX;
	FOR(y,H) {
		cin>>s;
		FOR(x,W) A[y][x]=s[x]-'0';
	}
	SY--,SX--;
	GY--,GX--;
	
	from[SY][SX]=1;
	FOR(i,T) {
		FOR(y,H) FOR(x,W) if(pat[A[y][x]][i]==0) from[y][x]=0;
		if(from[GY][GX]) {
			cout<<"Yes"<<endl;
			return;
		}
		ZERO(to);
		FOR(y,H) FOR(x,W) if(from[y][x]) {
			to[y+1][x]=to[y][x+1]=1;
			to[y][x]=1;
			if(y) to[y-1][x]=1;
			if(x) to[y][x-1]=1;
		}
		swap(from,to);
		
	}
	cout<<"No"<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
