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

int A[9][9];

int ok() {
	int y,x;
	FOR(y,9) {
		int num=0;
		FOR(x,9) {
			if(A[y][x]) num=0;
			else num++;
			if(num>=7) return 0;
			if(num+(8-x)<7) break;
		}
		num=0;
		FOR(x,9) {
			if(A[x][y]) num=0;
			else num++;
			if(num>=7) return 0;
			if(num+(8-x)<7) break;
		}
	}
	for(y=-2;y<=2;y++) {
		int num=0;
		FOR(x,9) {
			if(y+x<0 || y+x>=9 ||  A[y+x][x]) num=0;
			else num++;
			if(num>=7) return 0;
			if(num+(8-x)<7) break;
		}
	}
	for(y=6;y<=11;y++) {
		int num=0;
		FOR(x,9) {
			if(y-x<0 || y-x>=9 ||  A[y-x][x]) num=0;
			else num++;
			if(num>=7) return 0;
			if(num+(8-x)<7) break;
		}
	}
	return 1;
}

void dfs(int y) {
	int x;
	if(y==9) {
		int i,j;
		for(i=0;i<=8;i++) {
			A[i][7]=1;
			for(j=0;j<=8;j++) {
				A[j][8]=1;
				if(ok()) {
					FOR(y,9) {
						FOR(x,9) cout<<(".#"[A[y][x]]);
						cout<<endl;
					}
					exit(0);
				}
				A[j][8]=0;
			
			}
			A[i][7]=0;
		}
		return;
	}
	
	for(x=0;x<=6;x++) {
		A[y][x]=1;
		dfs(y+1);
		A[y][x]=0;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> V;
	dfs(0);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
