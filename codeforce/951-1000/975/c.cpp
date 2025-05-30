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
int N;
vector<int> E[505050];
int S[505050];
int NC[505050];
int vis[505050];
int P[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			E[i].clear();
			S[i]=0;
			vis[i]=0;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		int mi=1<<20;
		
		vector<int> A={0};
		int lef=N-1;
		int del=0;
		while(A.size()) {
			mi=min(mi,lef+del);
			vector<int> B;
			FORR(a,A) {
				vis[a]=1;
				NC[a]=E[a].size();
				if(a) NC[a]--;
				if(NC[a]==0) {
					x=a;
					while(x&&NC[x]==0) {
						del++;
						x=P[x];
						NC[x]--;
					}
				}
				else {
					FORR(b,E[a]) if(vis[b]==0) {
						P[b]=a;
						lef--;
						B.push_back(b);
					}
				}
			}
			swap(A,B);
		}
		cout<<mi<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
