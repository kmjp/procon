	#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int H,W,K;
string S[31];
int C[32][32][10];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			FOR(i,10) {
				C[y+1][x+1][i]=C[y][x+1][i]+C[y+1][x][i]-C[y][x][i];
			}
			C[y+1][x+1][S[y][x]-'0']++;
		}
	}
	
	int ma=0;
	FOR(y,H) FOR(x,W) {
		for(i=1;y+i<=H&&x+i<=W;i++) {
			FOR(j,10) {
				if(C[y+i][x+i][j]-C[y+i][x][j]-C[y][x+i][j]+C[y][x][j]+K>=i*i) ma=max(ma,i);
			}
		}
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
