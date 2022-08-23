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


int N,D;
ll P[101],Q[101];

ll from[3010][4020];
ll to[3010][4020];
const ll mo=998244353;
ll up[3010][4020];
ll down[3010][4020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N) {
		cin>>P[i];
	}
	from[D][D]=1;
	FOR(i,N) {
		cin>>Q[i];
		k=abs(P[i]-Q[i]);
		
		ZERO(to);
		
		FOR(x,3005) FOR(y,4010) {
			up[x][y]=down[x][y]=from[x][y];
			if(x&&y) (up[x][y]+=up[x-1][y-1])%=mo;
			if(x) (down[x][y]+=down[x-1][y+1])%=mo;
		}
		
		FOR(x,D+1) FOR(y,D+1) {
			/*
			for(r=1;x+r<=D&&y+k+r<=D;r++) {
				to[x][y]+=from[x+r][y+k+r];
			}
			*/
			r=min(D-x,D-(y+k));
			if(r>0) to[x][y]+=up[x+r][y+k+r]-up[x][y+k]+mo;
			
			/*
			for(r=k+1;x+r<=D&&y+r-k<=D;r++) {
				to[x][y]+=from[x+r][y+r-k];
			}
			*/
			r=min(D-x,D-(y-k));
			if(r>=k+1) to[x][y]+=up[x+r][y+r-k]-up[x+k][y]+mo;
			
			r=k;
			to[x][y]+=down[x+r][y+k-r];
			if(x) to[x][y]+=mo-down[x-1][y+k+1];
			/*
			for(r=0;r<=k;r++) {
				if(x+r<=D&&y+k-r<=D) to[x][y]+=from[x+r][y+k-r];
			}
			*/
			to[x][y]%=mo;
		}
		
		swap(from,to);
	}
	ll ret=0;
	FOR(x,D+1) FOR(y,D+1) ret+=from[x][y];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
