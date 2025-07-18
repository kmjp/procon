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
int N,Q;
ll A[2020][2020];
ll S[2020][2020];
ll SX[2020][2020];
ll SY[2020][2020];
int X1,X2,Y1,Y2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(y,N) {
			FOR(x,N) {
				cin>>A[y][x];
				S[y+1][x+1]=S[y+1][x]+S[y][x+1]-S[y][x]+A[y][x];
				SX[y+1][x+1]=SX[y+1][x]+SX[y][x+1]-SX[y][x]+A[y][x]*x;
				SY[y+1][x+1]=SY[y+1][x]+SY[y][x+1]-SY[y][x]+A[y][x]*y;
			}
		}
		while(Q--) {
			cin>>Y1>>X1>>Y2>>X2;
			X1--,Y1--;
			ll ret=0;
			ret+=SX[Y2][X2]-SX[Y2][X1]-SX[Y1][X2]+SX[Y1][X1];
			ret+=(S[Y2][X2]-S[Y2][X1]-S[Y1][X2]+S[Y1][X1])*(-X1+1);
			ret+=(SY[Y2][X2]-SY[Y2][X1]-SY[Y1][X2]+SY[Y1][X1])*(X2-X1);
			ret+=(S[Y2][X2]-S[Y2][X1]-S[Y1][X2]+S[Y1][X1])*(-Y1)*(X2-X1);
			
			
			
			
			cout<<ret<<" ";
			
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
