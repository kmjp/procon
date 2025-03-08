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
int A[202020];

int from[1<<18][19];
int to[1<<18][19];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(i,H) {
		cin>>s;
		y=0;
		FOR(x,W) if(s[x]=='1') y|=1<<x;
		from[y][0]++;
	}
	int mask;
	FOR(i,W) {
		FOR(y,W) {
			FOR(mask,1<<W) {
				to[mask][y]+=from[mask][y];
				to[mask^(1<<i)][y+1]+=from[mask][y];
			}
		}
		swap(from,to);
	}
	int mi=1<<30;
	FOR(mask,1<<W) {
		int sum=0;
		FOR(i,W+1) sum+=min(i,W-i)*from[mask][i];
		mi=min(mi,sum);
	}
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
