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

int T;
int H,W,Q;
const ll mo=998244353;
int Y[101010],X[101010],S[101010];

string P[2]={"ccss","sscc"};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>Q;
		int pat[2][4]={};
		FOR(y,4) FOR(x,2) pat[x][y]=1;
		cout<<8<<endl;
		
		FOR(i,Q) {
			cin>>y>>x>>s;
			y--,x--;
			FOR(j,4) if(P[y%2][(j+x)%4]!=s[0]) pat[0][j]=0;
			FOR(j,4) if(P[x%2][(j+y)%4]!=s[0]) pat[1][j]=0;
			int ret=0;
			FOR(y,4) FOR(x,2) ret+=pat[x][y];
			cout<<ret<<endl;
		}
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
