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
vector<int> E[202020];
int D[202020];
int C[202020];
vector<int> B[202020];
int L[202020];
int P[202020],S[202020],T[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	cin>>M;
	FOR(i,M) {
		cin>>x;
		C[x-1]=1;
		FORR(e,E[x-1]) B[e].push_back(x-1);
	}
	int sum=0;
	
	
	MINUS(L);
	queue<int> Q;
	int id=0;
	Q.push(0);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		L[x]=id++;
		FORR(e,E[x]) if(L[e]==-1) Q.push(e);
	}
	
	FOR(i,N) {
		S[i]=1<<20,T[i]=-1;
		FORR(e,E[i]) {
			if(L[e]<L[i]) P[i]=L[e];
			else {
				S[i]=min(S[i],L[e]);
				T[i]=max(T[i],L[e]);
			}
		}
	}
	
	FOR(i,N) {
		if(C[i]||B[i].size()) {
			sum++;
		}
		else {
			continue;
		}
		if(B[i].size()>=2) {
			D[L[i]]++;
			D[L[i]+1]--;
		}
		else if(B[i].empty()) {
			if(i) {
				D[P[i]]++;
				D[P[i]+1]--;
			}
			D[L[i]]++;
			D[L[i]+1]--;
			if(S[i]<=N) {
				D[S[i]]++;
				D[T[i]+1]--;
			}
		}
		else {
			x=B[i][0];
			if(C[i]) {
				D[L[i]]++;
				D[L[i]+1]--;
				D[L[x]]++;
				D[L[x]+1]--;
			}
			else {
				if(x) {
					D[P[x]]++;
					D[P[x]+1]--;
				}
				D[L[x]]++;
				D[L[x]+1]--;
				if(S[x]<1<<20) {
					D[S[x]]++;
					D[T[x]+1]--;
				}
			}
		}
	}
	FOR(i,N) D[i+1]+=D[i];
	FOR(i,N) cout<<sum-D[L[i]]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
