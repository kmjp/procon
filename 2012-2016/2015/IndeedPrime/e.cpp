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

int N,K;
ll X,S,A,B;
ll from[5050],to[5050];
deque<pair<ll,ll>> Q[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,K+1) from[i]=-1;
	from[0]=0;
	
	while(N--) {
		cin>>X>>S>>A>>B;
		if(B==0) {
			FOR(i,K+1) {
				to[i]=from[i];
				if(i-A>=0) to[i]=max(to[i],from[i-A]+S*X);
			}
		}
		else {
			FOR(i,B) Q[i].clear();
			FOR(i,K+1) {
				x=i%B;
				if(i>=A && from[i-A]>=0) {
					ll v=from[i-A]-(i-A)/B*X;
					while(Q[x].size() && Q[x].back().first<=v) Q[x].pop_back();
					Q[x].push_back({from[i-A]-(i-A)/B*X,i-A});
				}
				while(Q[x].size() && Q[x].front().second<=i-A-B*S) Q[x].pop_front();
				to[i]=from[i];
				if(Q[x].size()) {
					auto r=Q[x].front();
					to[i]=max(to[i],from[r.second]+(1+(i-A-r.second)/B)*X);
				}
			}
		}
		swap(to,from);
	}
	
	cout<<*max_element(from,from+K+1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
