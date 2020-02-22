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

int N,M,K;
int path[21][21];

int from[1<<19];
int to[1<<19];
ll mo=1000000007;

int add(int& a,int& b) {
	a+=b;
	if(a>=mo) a-=mo;
	return a;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(x,N) FOR(y,M+1) path[y][x]=3;
	N--;
	
	FOR(i,K) {
		cin>>x>>y>>j;
		path[x][y-1]=1<<j;
	}
	from[0]=1;
	
	for(int line=1;line<=M;line++) {
		for(int step=0;step<N;step++) {
			int sm=1<<step;
			ZERO(to);
			FOR(i,1<<N) if(from[i]) {
				if(path[line][step]&1) {
					if((i&sm)==0) add(to[i],from[i]);
				}
				if(path[line][step]&2) {
					if((i&sm)==0) {
						if(i<sm) add(to[i^sm],from[i]);
						else add(to[((i-sm)&i) | sm],from[i]);
					}
					else add(to[i],from[i]);
				}
			}
			swap(from,to);
		}
	}
	
	ll ret=0;
	FOR(i,1<<N) ret+=from[i];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
