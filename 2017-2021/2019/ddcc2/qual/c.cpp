#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W,K;
string S[303];
int A[303][303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	int id=1;
	FOR(y,H) {
		cin>>S[y];
		int num=0;
		FOR(x,W) if(S[y][x]=='#') num++;
		if(num==0) {
			if(y) {
				FOR(x,W) A[y][x]=A[y-1][x];
			}
		}
		else {
			int nex=id;
			FOR(x,W) {
				if(S[y][x]=='#') nex=id++;
				A[y][x]=nex;
			}
		}
	}
	
	for(y=H-1;y>=0;y--) if(A[y][0]==0) {
		FOR(x,W) A[y][x]=A[y+1][x];
	}
	
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
