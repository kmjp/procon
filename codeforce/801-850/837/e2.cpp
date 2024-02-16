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
string S[444];
int C[404][404];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) {
			if(c=='.') c=0;
			if(c=='m') c=1;
			if(c=='#') c=2;
		}
	}
	FOR(x,W) {
		FOR(y,H) {
			C[x][y+1]=C[x][y]+S[y][x];
		}
	}
	int ma=0;
	for(y=1;y<H-1;y++) {
		for(x=0;x<W;x++) {
			int cost=0;
			for(int x2=x;x2<W;x2++) {
				cost+=S[y][x2];
				if(cost>=2) break;
				if(x2-x<2) continue;
				int T0=y,T1=y,D0=y,D1=y;
				for(i=10;i>=0;i--) {
					if(T0-(1<<i)>=0&&C[x][y]-C[x][T0-(1<<i)]+C[x2][y]-C[x2][T0-(1<<i)]==0) T0-=1<<i;
					if(T1-(1<<i)>=0&&C[x][y]-C[x][T1-(1<<i)]+C[x2][y]-C[x2][T1-(1<<i)]<=1) T1-=1<<i;
					if(D0+(1<<i)<H&&C[x][D0+(1<<i)+1]-C[x][y+1]+C[x2][D0+(1<<i)+1]-C[x2][y+1]==0) D0+=1<<i;
					if(D1+(1<<i)<H&&C[x][D1+(1<<i)+1]-C[x][y+1]+C[x2][D1+(1<<i)+1]-C[x2][y+1]<=1) D1+=1<<i;
				}
				if(cost==0) {
					if(D0>y&&T1<y) ma=max(ma,x2-x-1+2*(D0-T1+1));
					if(D1>y&&T0<y) ma=max(ma,x2-x-1+2*(D1-T0+1));
				}
				if(cost==1) {
					if(D0>y&&T0<y) ma=max(ma,x2-x-1+2*(D0-T0+1));
				}
				
			}
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
