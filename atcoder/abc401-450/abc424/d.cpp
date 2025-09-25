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
string S[7];
int from[1<<7],to[1<<7];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		
		ZERO(from);
		int mask,mask1,mask2;
		FOR(y,H) {
			cin>>S[y];
			int cmask=0;
			FOR(x,W) if(S[y][x]=='#') cmask|=1<<x;
			FOR(mask,1<<W) to[mask]=1<<20;
			
			FOR(mask1,1<<W) {
				FOR(mask2,1<<W) if((cmask&mask2)==mask2) {
					int a=mask1&(mask1>>1);
					int b=mask2&(mask2>>1);
					if(a&b) continue;
					to[mask2]=min(to[mask2],from[mask1]+__builtin_popcount(cmask)-__builtin_popcount(mask2));
				}
			}
			swap(from,to);
		}
		int ret=1<<20;
		FOR(mask,1<<W) ret=min(ret,from[mask]);
		cout<<ret<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
