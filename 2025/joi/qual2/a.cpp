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

int H,W,Q;
int C[555][555];
int M[555][555];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	while(Q--) {
		cin>>i>>y>>x;
		y--,x--;
		if(i==1) {
			cin>>k;
			if(M[y][x]==0) C[y][x]=k;
			if(M[y][x+1]==0) C[y][x+1]=k;
			if(M[y+1][x]==0) C[y+1][x]=k;
			if(M[y+1][x+1]==0) C[y+1][x+1]=k;
		}
		else {
			M[y][x]++;
			M[y][x+1]++;
			M[y+1][x]++;
			M[y+1][x+1]++;
		}
	}
	FOR(y,H) {
		FOR(x,W) cout<<C[y][x]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
