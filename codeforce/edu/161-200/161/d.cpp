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

int T,N;
ll A[303030],D[303030];
int alive[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>D[i];
		set<int> L;
		set<int> Q;
		FOR(i,N) {
			alive[i]=1;
			L.insert(i);
			Q.insert(i);
		}
		
		FOR(i,N) {
			set<int> del;
			FORR(a,Q) {
				int s=0;
				auto it=L.find(a);
				if(it!=L.begin()) s+=A[*prev(it)];
				if(next(it)!=L.end()) s+=A[*next(it)];
				if(D[a]<s) del.insert(a);
			}
			cout<<del.size()<<" ";
			FORR(d,del) L.erase(d);
			Q.clear();
			FORR(a,del) {
				auto it=L.lower_bound(a);
				if(it!=L.end()) Q.insert(*it);
				if(it!=L.begin()) Q.insert(*prev(it));
			}
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
