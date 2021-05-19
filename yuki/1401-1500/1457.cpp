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

int N,M,X,Y,Z;
ll from[51][2555];
ll to[51][2555];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X>>Y>>Z;
	from[0][0]=1;
	int need=0;
	FOR(i,N) {
		cin>>x;
		if(x<=Y) continue;
		if(x>=X) need++;
		ZERO(to);
		FOR(j,i+1) FOR(k,2500) if(from[j][k]) {
			if(x<X) to[j][k]+=from[j][k];
			to[j+1][k+x]+=from[j][k];
		}
		
		swap(from,to);
	}
	
	if(need>M) return _P("Handicapped\n");
	ll ret=0;
	for(x=1;x<=M;x++) ret+=from[x][x*Z];
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
