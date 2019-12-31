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
ll A[101010];
ll from[101010],to[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>A[i];
	
	FOR(i,N) from[i]=A[i];
	FOR(i,K-1) {
		deque<pair<ll,int>> Q;
		FOR(j,N) {
			if(Q.empty()) {
				to[j]=-1LL<<60;
			}
			else {
				while(Q.size() && j-Q.front().second>M) Q.pop_front();
				to[j]=(i+2)*A[j] + Q.front().first;
			}
			while(Q.size() && Q.back().first<=from[j]) Q.pop_back();
			Q.push_back({from[j],j});
		}
		swap(from,to);
	}
	
	cout<<*max_element(from,from+N)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
