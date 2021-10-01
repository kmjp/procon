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
int M;
int C[202020];
int H[202020],done[202020],DC[202020];
int big[202020];
vector<int> B;
vector<int> E[202020];
vector<int> BE[202020];
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,N) C[i]=i,H[i]=-1,done[i]=-1;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) {
		if(E[i].size()>500) {
			big[i]=1;
			B.push_back(i);
		}
	}
	FOR(i,N) FORR(e,E[i]) if(big[e]) BE[i].push_back(e);
	
	FOR(i,Q) {
		cin>>x;
		int cur=x-1;
		FORR(b,BE[cur]) if(done[b]>H[cur]) {
			H[cur]=done[b];
			C[cur]=DC[b];
		}
		
		done[cur]=H[cur]=i;
		DC[cur]=C[cur];
		if(!big[cur]) {
			FORR(e,E[cur]) {
				H[e]=i;
				C[e]=C[cur];
			}
		}
	}
	FOR(i,N) {
		int cur=i;
		FORR(b,BE[cur]) if(done[b]>H[cur]) {
			H[cur]=done[b];
			C[cur]=DC[b];
		}
		cout<<C[cur]t+1<<" ";
	}
	cout<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
