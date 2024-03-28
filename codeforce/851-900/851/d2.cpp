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


int N,X[3030];
const ll mo=1000000007;
ll LP[3030][3030];
ll RP[3030][3030];
ll LS[3030][3030];
ll RS[3030][3030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i];
		RP[i][i]=RS[i][i]=1;
	}
	ll ret=0;
	FOR(y,N) {
		FOR(x,y+1) {
			if(y&&y>x+1) {
				(LS[x][y]+=LS[x][y-1])%=mo;
				(LP[x][y]+=LP[x][y-1])%=mo;
				(RS[x][y]+=RS[x][y-1])%=mo;
				(RP[x][y]+=RP[x][y-1])%=mo;
			}
			(LP[y][y+1]+=RP[x][y])%=mo;
			(LS[y][y+1]+=RS[x][y])%=mo;
			(RP[y][y+1]+=RP[x][y])%=mo;
			(RS[y][y+1]+=RS[x][y])%=mo;
			if(y>x) {
				k=lower_bound(X,X+N,X[y]+X[y]-X[x])-X;
				(LP[y][k]+=mo-RP[x][y])%=mo;
				(LS[y][k]+=mo-RS[x][y])%=mo;
				(RP[y][k]+=mo-RP[x][y])%=mo;
				(RS[y][k]+=mo-RS[x][y])%=mo;
				(LP[y][k]+=LP[x][y])%=mo;
				(LS[y][k]+=LS[x][y])%=mo;
				(RP[y][k]+=LP[x][y])%=mo;
				(RS[y][k]+=LP[x][y]+LS[x][y])%=mo;
			}
			
		}
	}
	FOR(y,N) {
		FOR(x,y+1) {
			ret+=LS[x][y];
		}
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
