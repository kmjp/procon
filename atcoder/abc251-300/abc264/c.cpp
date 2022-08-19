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


int H1,H2,W1,W2;
int A[10][10];
int B[10][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H1>>W1;
	FOR(y,H1) FOR(x,W1) cin>>A[y][x];
	cin>>H2>>W2;
	FOR(y,H2) FOR(x,W2) cin>>B[y][x];
	
	int mask1,mask2;
	FOR(mask1,1<<H1) if(__builtin_popcount(mask1)==H2) {
		FOR(mask2,1<<W1) if(__builtin_popcount(mask2)==W2) {
			vector<int> Y,X;
			FOR(i,H1) if(mask1&(1<<i)) Y.push_back(i);
			FOR(i,W1) if(mask2&(1<<i)) X.push_back(i);
			int ok=1;
			FOR(y,H2) FOR(x,W2) if(A[Y[y]][X[x]]!=B[y][x]) ok=0;
			if(ok) {
				cout<<"Yes"<<endl;
				return;
			}
			
		}
	}
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
