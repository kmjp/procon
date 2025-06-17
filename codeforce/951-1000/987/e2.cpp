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
int P[1010101];
vector<int> C[1010101];
multiset<int> V[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			C[i].clear();
			V[i].clear();
		}
		FOR(i,N-1) {
			cin>>P[i+1];
			P[i+1]--;
			C[P[i+1]].push_back(i+1);
		}
		
		for(i=N-1;i>=0;i--) {
			if(V[i].empty()) {
				V[P[i]].insert(0);
			}
			else {
				while(V[i].size()==1) V[i].insert(0);
				while(V[i].size()>2) {
					x=*V[i].begin();
					V[i].erase(V[i].begin());
					y=*V[i].begin();
					V[i].erase(V[i].begin());
					V[i].insert(y+1);
				}
				if(i) V[P[i]].insert(*V[i].rbegin()+1);
			}
		}
		cout<<*V[0].rbegin()+1<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
