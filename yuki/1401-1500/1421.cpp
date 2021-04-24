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


int mat[10000][50];
int V[10000];
int R[50];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H;
	FOR(i,H) {
		cin>>x;
		FOR(j,x) {
			cin>>y;
			mat[i][y-1]=1;
		}
		cin>>V[i];
	}
	
	int fix=0;
	
	FOR(i,W) {
		for(j=fix;j<H;j++) if(mat[j][i]) break;
		if(j>=H) continue;
		FOR(k,W) swap(mat[fix][k],mat[j][k]);
		swap(V[fix],V[j]);
		
		FOR(j,H) if(j!=fix&&mat[j][i]) {
			V[j]^=V[fix];
			for(k=i;k<W;k++) mat[j][k]^=mat[fix][k];
		}
		fix++;
	}
	
	
	FOR(i,H) {
		FOR(x,W) if(mat[i][x]) break;
		if(x<W) R[x]=V[i];
		else if(V[i]) {
			cout<<-1<<endl;
			return;
		}
	}
	FOR(i,W) cout<<R[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
