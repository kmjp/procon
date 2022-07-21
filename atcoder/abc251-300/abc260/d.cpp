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

int N,K;
int P[202020];

int nex[202020];
int num[202020];

int ret[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(ret);
	cin>>N>>K;
	set<int> S;
	FOR(i,N) {
		cin>>x;
		auto it=S.lower_bound(x);
		if(it==S.end()) {
			nex[x]=0;
			num[x]=1;
		}
		else {
			nex[x]=*it;
			num[x]=num[*it]+1;
			S.erase(it);
		}
		S.insert(x);
		
		if(num[x]==K) {
			S.erase(x);
			while(x) {
				ret[x]=i+1;
				x=nex[x];
			}
		}
		
	}
	FOR(i,N) cout<<ret[i+1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
