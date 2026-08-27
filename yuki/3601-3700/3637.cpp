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

int N,Q;
string S;
set<int> V[256];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	FOR(i,N) V[S[i]].insert(i);
	
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>s;
			x--;
			V[S[x]].erase(x);
			S[x]=s[0];
			V[S[x]].insert(x);
		}
		else {
			cin>>s;
			int cur=0;
			FORR(c,s) {
				auto it=V[c].lower_bound(cur);
				if(it==V[c].end()) {
					cur=-1;
					break;
				}
				cur=*it+1;
			}
			if(cur==-1) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
