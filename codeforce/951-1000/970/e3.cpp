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

int T,N;
string S;

int C[2][26][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		FOR(x,2) FOR(y,26) C[x][y][0]=0;
		FOR(i,N) {
			FOR(x,2) FOR(y,26) C[x][y][i+1]=C[x][y][i];
			C[i%2][S[i]-'a'][i+1]++;
		}
		
		int ret;
		if(N%2==0) {
			int ma[2]={0,0};
			FOR(x,26) {
				ma[0]=max(ma[0],C[0][x][N]);
				ma[1]=max(ma[1],C[1][x][N]);
			}
			ret=N-ma[0]-ma[1];
		}
		else {
			ret=N;
			FOR(i,N) {
				int ma[2]={0,0};
				FOR(x,26) {
					ma[0]=max(ma[0],C[0][x][i]+C[1][x][N]-C[1][x][i+1]);
					ma[1]=max(ma[1],C[1][x][i]+C[0][x][N]-C[0][x][i+1]);
				}
				ret=min(ret,N-ma[0]-ma[1]);
			}
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
