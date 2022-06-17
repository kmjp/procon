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

int T,H,W;
string S[505];
int L[505][505],R[505][505];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ZERO(L);
		ZERO(R);
		cin>>H>>W;
		FOR(y,H) {
			cin>>S[y];
			FOR(x,W) {
				if(S[y][x]=='*') L[y][x+1]=L[y][x]+1;
			}
			for(x=W;x>=1;x--) {
				if(S[y][x-1]=='*') R[y][x]=R[y][x+1]+1;
			}
		}
		int ret=0;
		FOR(y,H) {
			FOR(x,W) {
				int mi=y+1;
				for(int y2=y;y2>=0;y2--) {
					if(S[y2][x]=='.') {
						mi=min(mi,y-y2);
					}
					else {
						mi=min(mi,(y-y2)+min(L[y2][x+1],R[y2][x+1]));
					}
				}
				ret+=mi;
			}
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
