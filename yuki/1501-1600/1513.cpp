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

int N,K;
const ll mo=998244353;

ll fromp[202][202];
ll froms[202][202];

ll ps[202];
ll ss[202];
ll top[202][202];
ll tos[202][202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>K;
	
	FOR(x,K) FOR(y,K) if(x!=y) {
		fromp[x][y]=1;
		froms[x][y]=x+y;
	}
	FOR(i,N-2) {
		ZERO(top);
		ZERO(tos);
		
		
		FOR(y,K) {
			FOR(x,K) {
				ps[x+1]=(ps[x]+fromp[x][y])%mo;
				ss[x+1]=(ss[x]+froms[x][y])%mo;
			}
			FOR(x,K) {
				if(x<y) {
					top[y][x]=(ps[y]+mo-fromp[x][y])%mo;
					tos[y][x]=(ss[y]+mo-froms[x][y]+x*top[y][x])%mo;
				}
				else if(x>y) {
					top[y][x]=((ps[K]-ps[y])+mo-fromp[x][y])%mo;
					tos[y][x]=((ss[K]-ss[y])+mo-froms[x][y]+x*top[y][x])%mo;
				}
			}
			
		}
		swap(fromp,top);
		swap(froms,tos);
	}
	
	ll ret1=0,ret2=0;
	FOR(x,K) FOR(y,K) {
		ret1+=fromp[x][y];
		ret2+=froms[x][y];
	}
	cout<<ret1%mo<<" "<<ret2%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
