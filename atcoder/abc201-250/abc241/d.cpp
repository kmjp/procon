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


int Q;
multiset<ll> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,5) M.insert(-1),M.insert(1LL<<60);
	FOR(i,Q) {
		ll V;
		cin>>j>>V;
		if(j==1) {
			M.insert(V);
		}
		else {
			cin>>k;
			if(j==2) {
				auto it=M.lower_bound(V+1);
				FOR(j,k) it--;
				cout<<*it<<endl;
			}
			else {
				auto it=M.lower_bound(V);
				FOR(j,k-1) it++;
				if(*it==1LL<<60) cout<<-1<<endl;
				else cout<<*it<<endl;
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
