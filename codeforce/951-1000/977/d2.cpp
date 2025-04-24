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
ll A[202020];
ll FL[202020],FR[202020];
ll TL[202020],TR[202020];
ll from[2],to[2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(i,T) {
		cin>>H>>W;
		ll mi=0;
		
		
		FOR(x,W) {
			cin>>y;
			A[x+1]=A[x]+y;
			FR[x+1]=A[x+1]-mi;
			mi=min(mi,A[x+1]);
		}
		ll ma=A[W];
		for(x=W-1;x>=0;x--) {
			FL[x]=ma-A[x];
			ma=max(ma,A[x]);
		}
		FL[W]=FR[0]=-1LL<<60;
		
		FOR(y,H-1) {
			FOR(x,W) {
				cin>>k;
				A[x+1]=A[x]+k;
			}
			from[0]=0;
			from[1]=-1LL<<60;
			TR[0]=-1LL<<60;
			for(x=1;x<=W;x++) {
				TR[x]=from[1]+A[x];
				to[0]=max(from[0],-A[x]);
				to[1]=max({from[1],from[0]+FL[x],from[0]+FR[x]});
				swap(from,to);
			}
			from[0]=A[W];
			from[1]=-1LL<<60;
			TL[W]=-1LL<<60;
			for(x=W-1;x>=0;x--) {
				TL[x]=from[1]-A[x];
				to[0]=max(from[0],A[x]);
				to[1]=max({from[1],from[0]+FL[x],from[0]+FR[x]});
				swap(from,to);
			}
			
			FOR(x,W+2) FL[x]=TL[x], FR[x]=TR[x];
		}
		ll ret=-1LL<<60;
		FOR(x,W+1) ret=max({ret,FL[x],FR[x]});
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
