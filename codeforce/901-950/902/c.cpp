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
int A[202020];
vector<int> E[202020];
int in[202020];
int C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		E[A[i]].push_back(i);
		in[A[i]]++;
	}
	queue<int> Q;
	FOR(i,N) {
		if(in[i]==0) Q.push(i);
	}
	MINUS(C);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		if(C[cur]>=0) continue;
		C[cur]=0;
		FORR(e,E[cur]) if(C[e]==0) C[cur]=1;
		in[A[cur]]--;
		if(in[A[cur]]==0||C[cur]==0) Q.push(A[cur]);
	}
	FOR(i,N) if(C[i]==-1) {
		vector<int> V={i};
		while(A[V.back()]!=i) {
			V.push_back(A[V.back()]);
		}
		if(V.size()%2) {
			cout<<"-1"<<endl;
			return;
		}
		FOR(j,V.size()) {
			C[V[j]]=j%2;
		}
	}
	vector<int> cand;
	FOR(i,N) {
		x=0;
		FORR(e,E[i]) if(C[e]==0) x++;
		if(x>0 != C[i]) {
			cout<<"-1"<<endl;
			return;
		}
		if(C[i]==0) cand.push_back(A[i]+1);
	}
	cout<<cand.size()<<endl;
	FORR(e,cand) cout<<e<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
