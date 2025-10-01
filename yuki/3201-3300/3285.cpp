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
int A[303][303];
const ll mo=998244353;
ll from[1<<17];
ll to[1<<17];
ll from2[1<<17][2][2];
ll to2[1<<17][2][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	
	if(W==1) {
		cout<<H<<endl;
		return;
	}
	if(H==1) {
		FOR(x,W) if(A[0][x]!=A[0][0]) {
			cout<<0<<endl;
			return;
		}
		cout<<1<<endl;
		return;
	}
	
	ll ret=0;
	int mask;
	if(H<=W) {
		FOR(i,H) {
			int v=A[i][0];
			ZERO(from);
			mask=0;
			FOR(y,H) if(i!=y&&A[y][0]==v) mask|=1<<y;
			if(A[i][1]==v) mask|=1<<i;
			from[mask]=1;
			for(x=2;x<W;x++) {
				ZERO(to);
				FOR(mask,1<<H) if(from[mask]) {
					FOR(y,H) if(mask&(1<<y)) {
						int nmask=mask^(1<<y);
						if(A[y][x]==v) nmask|=1<<y;
						(to[nmask]+=from[mask])%=mo;
					}
				}
				swap(from,to);
			}
			FOR(mask,1<<H) ret+=from[mask]*__builtin_popcount(mask)%mo;
		}
	}
	else {
		W-=2;
		FOR(i,H) {
			int v=A[i][0];
			ZERO(from2);
			from2[0][0][0]=1;
			FOR(y,H) {
				FOR(mask,1<<W) FOR(j,2) FOR(k,2) {
					to2[mask][j][k]=from2[mask][j][k];
					from2[mask][j][k]=0;
				}
				FOR(mask,1<<W) FOR(j,2) FOR(k,2) from2[mask][A[y][i==y]==v][k]+=to2[mask][j][k];
				FOR(x,W) {
					FOR(mask,1<<W) FOR(k,2) if((mask&(1<<x))==0) from2[mask^(1<<x)][A[y][x+2]==v][k]+=from2[mask][1][k];
				}
				FOR(mask,1<<W) FOR(j,2) FOR(k,2) {
					to2[mask][j][k]=from2[mask][j][k];
					from2[mask][j][k]=0;
				}
				FOR(mask,1<<W) {
					from2[mask][0][0]=(to2[mask][0][0]+to2[mask][1][0])%mo;
					from2[mask][0][1]=(to2[mask][1][0]+to2[mask][0][1]+to2[mask][1][1])%mo;
				}
			}
			ret+=from2[(1<<W)-1][0][1];
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
