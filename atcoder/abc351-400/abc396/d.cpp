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
ll E[10][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) E[x][y]=-1;
	FOR(i,M) {
		ll v;
		cin>>x>>y>>v;
		E[x-1][y-1]=E[y-1][x-1]=v;
	}
	
	ll ret=1LL<<60;
	vector<int> P;
	FOR(i,N) P.push_back(i);
	do {
		
		if(P[0]==0) {
			ll cur=0;
			FOR(i,N) {
				if(E[P[i]][P[i+1]]==-1) {
					cur=1LL<<60;
					break;
				}
				cur^=E[P[i]][P[i+1]];
				if(P[i+1]==N-1) break;
				
			}
			ret=min(ret,cur);
		}
		
	} while(next_permutation(ALL(P)));
	
	if(ret==1LL<<60) ret=-1;
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
