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

int N,M;
int A[3030];
ll from[3030][2];
ll to[3030][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N+1) from[i][0]=from[i][1]=-1LL<<60;
	from[0][0]=0;
	FOR(i,N) {
		cin>>x;
		
		FOR(j,N+1) to[j][0]=to[j][1]=-1LL<<60;
		FOR(j,N+1) {
			to[j][0]=max(from[j][0]+x,from[j][1]+x);
			to[j+1][1]=from[j][0];
		}
		swap(from,to);
	}
	cout<<max(from[M][0],from[M][1])<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
