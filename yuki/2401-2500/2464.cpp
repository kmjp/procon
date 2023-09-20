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
vector<int> E[303030];
vector<pair<int,int>> R;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
	}
	
	
	FOR(i,N) {
		vector<int> V;
		set<int> S;
		V.push_back(i);
		S.insert(i);
		while(V.size()) {
			while(E[V.back()].size()) {
				x=E[V.back()].back();
				E[V.back()].pop_back();
				if(S.count(x)) {
					while(V.back()!=x) {
						S.erase(V.back());
						V.pop_back();
					}
					continue;
				}
				S.insert(x);
				V.push_back(x);
			}
			if(V.size()>=2) {
				S.erase(V.back());
				R.push_back({V[V.size()-2]+1,V[V.size()-1]+1});
			}
			V.pop_back();
		}
	}
	cout<<N<<" "<<R.size()<<endl;
	FORR2(a,b,R) cout<<a<<" "<<b<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
