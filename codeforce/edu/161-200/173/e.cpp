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
int H,W;
int A[1111][1111];
int B[1111][1111];
int C[1111][1111];
int D[1111][1111];
int RR[1111],CC[1111];
int NR[1111],NC[1111];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) FOR(x,W) cin>>A[y][x];
		FOR(y,H) FOR(x,W) cin>>B[y][x];
		
		int ok=1;
		FOR(i,30) {
			FOR(y,H) RR[y]=1, NR[y]=0;
			FOR(x,W) CC[x]=1, NC[x]=0;
			FOR(y,H) FOR(x,W) {
				C[y][x]=(A[y][x]>>i)&1;
				D[y][x]=(B[y][x]>>i)&1;
				if(D[y][x]) NR[y]++,NC[x]++;
			}
			int AR=H,AC=W;
			set<int> cand;
			
			FOR(y,H) if(RR[y]&&(NR[y]==0)) RR[y]=0,cand.insert(y);
			FOR(x,W) if(CC[x]&&(NC[x]==AR)) CC[x]=0, cand.insert(H+x);
			while(AR&&AC&&cand.size()) {
				y=*cand.begin();
				cand.erase(y);
				if(y<H) {
					AR--;
					FOR(x,W) if(CC[x]) {
						if(D[y][x]) NC[x]--;
						if(NC[x]==AR) CC[x]=0,cand.insert(x+H);
					}
				}
				else {
					x=y-H;
					AC--;
					FOR(y,H) if(RR[y]) {
						if(D[y][x]) NR[y]--;
						if(NR[y]==0) RR[y]=0,cand.insert(y);
					}
				}
			}
			FOR(y,H) FOR(x,W) if(RR[y]&&CC[x]&&C[y][x]!=D[y][x]) ok=0;
			
		}
		if(ok) cout<<"Yes"<<"\n";
		else cout<<"No"<<"\n";
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
