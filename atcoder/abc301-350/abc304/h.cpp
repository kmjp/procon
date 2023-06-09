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
vector<int> E[202020],RE[202020];
int in[202020],in2[202020];
int L[202020],R[202020];
int P[202020];
vector<int> ev[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		RE[y-1].push_back(x-1);
		in[x-1]++;
		in2[y-1]++;
	}
	FOR(i,N) {
		cin>>L[i]>>R[i];
	}
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		vector<int> C;
		FORR(e,E[cur]) {
			C.push_back(R[e]);
		}
		sort(ALL(C));
		FOR(i,C.size()) R[cur]=min(R[cur],C[i]-(i+1));
		FORR(e,RE[cur]) if(--in[e]==0) Q.push(e);
		in[cur]=-1;
	}
	
	FOR(i,N) {
		if(in[i]>=0) {
			cout<<"No"<<endl;
			return;
		}
		if(L[i]>R[i]) {
			cout<<"No"<<endl;
			return;
		}
		if(in2[i]==0) ev[L[i]].push_back(i);
	}
	set<pair<int,int>> cand;
	for(i=1;i<=N;i++) {
		FORR(e,ev[i]) {
			cand.insert({R[e],e});
		}
		if(cand.empty()) {
			cout<<"No"<<endl;
			return;
		}
		x=cand.begin()->second;
		cand.erase(cand.begin());
		if(R[x]<i) {
			cout<<"No"<<endl;
			return;
		}
		P[x]=i;
		FORR(e,E[x]) {
			--in2[e];
			if(in2[e]==0) {
				if(L[e]<=i) {
					cand.insert({R[e],e});
				}
				else {
					ev[L[e]].push_back(e);
				}
			}
		}
	}
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<P[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
