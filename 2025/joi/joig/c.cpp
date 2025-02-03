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
int p3[13];
int V[9*9*9*9*9*9+5][13];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	p3[0]=1;
	FOR(i,N) p3[i+1]=p3[i]*3;
	cin>>s;
	FOR(i,p3[N]) {
		V[i][0]=s[i]-'A';
	}
	FOR(i,N) {
		FOR(j,p3[N-1-i]) {
			x=V[j*3][i]+V[j*3+1][i]+V[j*3+2][i];
			V[j][i+1]=(x>=2);
		}
	}
	while(Q--) {
		cin>>x;
		x--;
		V[x][0]^=1;
		FOR(i,N) {
			x/=3;
			y=V[x*3][i]+V[x*3+1][i]+V[x*3+2][i];
			V[x][i+1]=(y>=2);
		}
		cout<<(char)('A'+V[0][N])<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
