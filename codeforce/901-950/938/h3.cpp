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

int T,H,W,K;
int D[51][51];
int R,C,P;
ll p3[20];
const int DI=12;
ll from[1<<DI],to[1<<DI];
string S[55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,51) FOR(x,51) {
		k=y*y+x*x;
		FOR(i,100) if(i*i>=k) {
			D[y][x]=i;
			break;
		}
	}
	p3[0]=1;
	FOR(i,18) p3[i+1]=p3[i]*3;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K;
		FOR(y,H) cin>>S[y];
		int mask;
		FOR(mask,1<<DI) from[mask]=-1LL<<60;
		from[0]=0;
		
		FOR(i,K) {
			cin>>R>>C>>P;
			R--;
			C--;
			int dam[DI+1]={};
			FOR(y,H) FOR(x,W) if(S[y][x]=='#') {
				k=D[abs(y-R)][abs(x-C)];
				for(j=k;j<=DI;j++) dam[j]+=P;
			}
			for(mask=(1<<DI)-1;mask>=0;mask--) {
				FOR(j,DI) if((mask&(1<<j))==0) chmax(from[mask^(1<<j)],from[mask]+dam[j+1]-p3[j+1]);
			}
		}
		ll ret=0;
		FOR(mask,1<<DI) {
			ret=max(ret,from[mask]);
		}
		cout<<ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
