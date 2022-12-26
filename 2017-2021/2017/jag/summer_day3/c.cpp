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

int N;
int mat[10100][10100];
int E[10100];
int ret[101][101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*(N*N-N)) {
		cin>>x>>y;
		mat[x][y]=mat[y][x]=1;
		E[x]++;
		E[y]++;
	}
	
	for(i=1;i<=N*N;i++) if(E[i]==2) break;
	int cur=i;
	ret[0][0]=cur;
	for(x=1;x<N;x++) {
		for(j=1;j<=N*N;j++) if(mat[cur][j]==1 && E[j]<4) break;
		mat[cur][j]=mat[j][cur]=0;
		E[cur]--;
		cur=j;
		E[cur]--;
		ret[0][x]=cur;
	}
	cur=i;
	for(x=1;x<N;x++) {
		for(j=1;j<=N*N;j++) if(mat[cur][j]==1 && E[j]<4) break;
		mat[cur][j]=mat[j][cur]=0;
		E[cur]--;
		cur=j;
		E[cur]--;
		ret[x][0]=cur;
	}
	
	for(y=1;y<N;y++) {
		for(x=1;x<N;x++) {
			for(i=1;i<=N*N;i++) if(E[i]>0 && mat[ret[y-1][x]][i] && mat[ret[y][x-1]][i]) {
				E[i]=0;
				ret[y][x]=i;
				break;
			}
		}
	}
	
	FOR(y,N) {
		FOR(x,N) cout<<ret[y][x]<<" ";
		cout<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
