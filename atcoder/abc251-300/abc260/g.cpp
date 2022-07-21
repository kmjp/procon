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

int N,M;
string S[2020];
int LR[4020][6040];
int UD[4020][6040];
int sum[4020][6040];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(y,N) {
		cin>>S[y];
		FOR(x,6020) {
			if(x<N) {
				LR[y+1][x+1]=S[y][x]=='O';
				UD[y+1][x+1]=S[y][x]=='O';
			}
			LR[y+1][x+1]+=LR[y+1][x];
			UD[y+1][x+1]+=UD[y][x+1];
		}
	}
	FOR(x,6010) {
		int ret=0;
		int cx=x;
		FOR(y,N) {
			if(cx<0) break;
			ret+=LR[y+1][cx+1]-LR[y+1][max(cx-2*M+1,0)];
			sum[y][cx]=ret;
			ret-=UD[y+1][cx+1]-UD[max(y+1-M,0)][cx+1];
			ret-=UD[y+1][cx]-UD[max(y+1-M,0)][cx];
			cx-=2;
		}
	}
	
	
	int Q;
	cin>>Q;
	while(Q--) {
		cin>>y>>x;
		cout<<sum[y-1][x-1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
