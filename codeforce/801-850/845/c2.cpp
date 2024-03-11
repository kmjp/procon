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

int T,N,M,A[101010];

vector<int> cand[101010];
map<int,int> C;
set<int> emp;

void add(int v) {
	FORR(c,cand[v]) if(c<=M) {
		C[c]++;
		emp.erase(c);
	}
}
void del(int v) {
	FORR(c,cand[v]) if(c<=M) {
		C[c]--;
		if(C[c]==0) emp.insert(c);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=100000;i++) {
		for(j=i;j<=100000;j+=i) cand[j].push_back(i);
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) cin>>A[i];
		sort(A,A+N);
		int mi=1<<20;
		
		C.clear();
		emp.clear();
		for(i=1;i<=M;i++) emp.insert(i);
		for(int L=0,R=0;L<N;L++) {
			while(R<N&&emp.size()) {
				add(A[R]);
				R++;
			}
			if(emp.empty()) {
				mi=min(mi,A[R-1]-A[L]);
			}
			del(A[L]);
		}
		
		
		if(mi==1<<20) mi=-1;
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
