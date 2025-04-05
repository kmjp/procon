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

int T,L,H,W;
int A[1515];
int B[1515][1515];
int dp0[1515][1515];
int dp1[1515][1515];
int pos[1515*1515];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(pos);
	
	cin>>T;
	while(T--) {
		cin>>L>>H>>W;
		FOR(i,L) {
			cin>>A[i];
		}
		FOR(i,L) {
			if(pos[A[i]]==-1) {
				pos[A[i]]=i;
			}
			else {
				break;
			}
		}
		FOR(y,H) FOR(x,W) cin>>B[y][x];
		FOR(y,H+2) FOR(x,W+2) dp0[y][x]=dp1[y][x]=1<<30;
		for(y=H-1;y>=0;y--) for(x=W-1;x>=0;x--) {
			dp0[y][x]=min(dp0[y][x+1],dp0[y+1][x]);
			dp1[y][x]=min(dp1[y][x+1],dp1[y+1][x]);
			
			int p=pos[B[y][x]];
			if(p>=0) {
				if(p%2==0&&p+3<=dp1[y+1][x+1]) dp0[y][x]=min(dp0[y][x],p);
				if(p%2==1&&p+3<=dp0[y+1][x+1]) dp1[y][x]=min(dp1[y][x],p);
			}
			
		}
		
		if(dp0[0][0]==0) {
			cout<<"T"<<endl;
		}
		else {
			cout<<"N"<<endl;
		}
		FOR(i,L) pos[A[i]]=-1;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
