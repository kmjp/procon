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

int N;
vector<int> E[5050];
int ret[5050];
int D[5050];

void solve() {
	int i,j,k,l,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) {
		queue<int> Q;
		MINUS(D);
		D[i]=0;
		Q.push(i);
		int sum=0;
		int step=1;
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			
			sum+=D[x];
			ret[step]=max(ret[step],(N-1)*step-sum*2);
			step++;
			FORR(e,E[x]) if(D[e]==-1) {
				D[e]=D[x]+1;
				Q.push(e);
			}
		}
	}
	
	
	
	FOR(i,N+1) cout<<ret[i]<<" ";
	cout<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
