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

int N,Q;
int M[505][505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>j>>x;
		x--;
		if(j==1) {
			cin>>y;
			y--;
			M[x][y]=1;
		}
		else if(j==2) {
			FOR(j,N) if(M[j][x]) M[x][j]=1;
		}
		else {
			vector<int> add;
			FOR(j,N) FOR(y,N) if(M[x][j] && M[j][y] && x!=y) add.push_back(y);
			FORR(y,add) M[x][y]=1;
		}
	}
	
	FOR(y,N) {
		M[y][y]=0;
		FOR(x,N) {
			if(M[y][x]) cout<<"Y";
			else cout<<"N";
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
