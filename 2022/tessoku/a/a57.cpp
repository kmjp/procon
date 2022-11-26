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

int N,Q;
int nex[101010][30];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	for(i=1;i<=N;i++) cin>>nex[i][0];
	FOR(i,29) {
		for(j=1;j<=N;j++) nex[j][i+1]=nex[nex[j][i]][i];
	}
	while(Q--) {
		int X,Y;
		cin>>X>>Y;
		FOR(j,30) if(Y&(1<<j)) X=nex[X][j];
		cout<<X<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
