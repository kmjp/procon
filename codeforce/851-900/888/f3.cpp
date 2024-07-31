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
int N,K;
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		vector<pair<int,int>> V;
		FOR(i,N) {
			cin>>A[i];
			V.push_back({A[i],i});
		}
		sort(ALL(V));
		int a=0,b=0,x=0,v=-1;
		FOR(i,N-1) {
			int tx=0;
			FOR(j,K) {
				if((V[i].first&(1<<j))==0&&(V[i+1].first&(1<<j))==0) tx|=1<<j;
			}
			int tv=(tx^V[i].first)&(tx^V[i+1].first);
			if(tv>v) {
				a=V[i].second+1;
				b=V[i+1].second+1;
				x=tx;
				v=tv;
			}
		}
		cout<<a<<" "<<b<<" "<<x<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
