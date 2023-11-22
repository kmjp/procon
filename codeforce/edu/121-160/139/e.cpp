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

int N;
ll from[4][4][4];
ll to[4][4][4];
ll ret=0;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	FOR(i,N) {
		cin>>j;
		ZERO(to);
		ll s=0;
		FOR(x,4) FOR(y,4) FOR(k,4) if(from[x][y][k]) {
			s+=from[x][y][k];
			if(j&x) {
				to[j][y][k]+=from[x][y][k];
			}
			else if(j&y) {
				to[x][j][k]+=from[x][y][k];
			}
			else if(j&k) {
				to[x][y][j]+=from[x][y][k];
			}
			else {
				ret+=from[x][y][k]*(N-i);
				if(j==0) {
					to[x][y][k]+=from[x][y][k];
				}
				else {
					if(x==0) to[j][y][k]+=from[x][y][k];
					else if(y==0) to[x][j][k]+=from[x][y][k];
					else if(k==0) to[x][y][j]+=from[x][y][k];
					else {
						assert(0);
					}
				}
			}
		}
		to[j][0][0]++;
		ret+=(N-i);
		swap(from,to);
	}
	//FOR(x,4) FOR(y,4) FOR(k,4) ret+=from[x][y][k];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
