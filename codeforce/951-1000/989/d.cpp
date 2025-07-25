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

int T,N,A[202020];

int S[3][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int sum=0;
		set<int> S[3];
		FOR(i,N) {
			cin>>A[i];
			S[A[i]].insert(i);
		}
		vector<pair<int,int>> V;
		FOR(i,N) {
			if(S[0].size()) {
				S[A[i]].erase(i);
				if(A[i]==2) {
					x=*S[1].rbegin();
					S[1].erase(x);
					V.push_back({i,x});
					A[i]--;
					A[x]++;
					S[2].insert(x);
					
				}
				if(A[i]==1) {
					x=*S[0].rbegin();
					S[0].erase(x);
					V.push_back({i,x});
					A[i]--;
					A[x]++;
					S[1].insert(x);
				}
			}
			else if(S[1].size()) {
				S[A[i]].erase(i);
				if(A[i]==2) {
					x=*S[1].rbegin();
					S[1].erase(x);
					V.push_back({i,x});
					A[i]--;
					A[x]++;
					S[2].insert(x);
					
				}
			}
			else {
				S[A[i]].erase(i);
			}
		}
		assert(V.size()<=N);
		cout<<V.size()<<endl;
		FORR2(a,b,V) cout<<a+1<<" "<<b+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
