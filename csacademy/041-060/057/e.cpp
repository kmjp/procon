#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
int H,W,K,S;
ll mo=1000000007;

ll DX[3030][3030];
ll DY[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K>>S;
		ll ret=0;
		FOR(i,K+1) {
			FOR(y,H+1) DY[i][y]=0;
			FOR(x,W+1) DX[i][x]=0;
		}
		DX[0][0]=1;
		DY[0][0]=1;
		FOR(i,K) {
			FOR(y,H+1) {
				if(y) (DY[i+1][y-1]+=DY[i][y]*y)%=mo;
				if(y+1<=H) (DY[i+1][y+1]+=DY[i][y]*(H-y))%=mo;
			}
			FOR(x,W+1) {
				if(x) (DX[i+1][x-1]+=DX[i][x]*x)%=mo;
				if(x+1<=W) (DX[i+1][x+1]+=DX[i][x]*(W-x))%=mo;
			}
		}
		
		FOR(y,H+1) FOR(x,W+1) {
			if(y*W+x*H-2*y*x!=S) continue;
			(ret+=DX[K][x]*DY[K][y])%=mo;
		}
		
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
