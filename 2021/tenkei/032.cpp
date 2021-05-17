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
int A[10][10];
int ng[10][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>A[y][x];
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		ng[x-1][y-1]=ng[y-1][x-1]=1;
	}
	int ret=1<<30;
	vector<int> V;
	FOR(i,N) V.push_back(i);
	do {
		int sum=0;
		FOR(i,V.size()) {
			if(i&&ng[V[i]][V[i-1]]) {
				sum=1<<30;
				break;
			}
			sum+=A[V[i]][i];
		}
		ret=min(ret,sum);
	} while(next_permutation(ALL(V)));
	
	if(ret==1<<30) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
