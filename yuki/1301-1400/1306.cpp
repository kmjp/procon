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


int N=0;
int A[5050],B[5050];
map<pair<int,int>,int> table[2525];
vector<int> pat; //={11,9,6,15,14,20,21,24,10,23,16,19,17,5,8,7,13,18,22,12};

map<pair<int,int>,pair<int,int>> memo;

pair<int,int> ask(int x,int y) {
	if(x==y) return {0,0};
	if(memo.count({x,y})) return memo[{x,y}];
	
	cout<<"? "<<(x+1)<<" "<<(y+1)<<endl;
	int a,b;
	
	if(pat.empty()) {
		cin>>a>>b;
	}
	else {
		a=pat[x]/N-pat[y]/N;
		b=pat[x]%N-pat[y]%N;
		if(a>b) swap(a,b);
	}
	return memo[{x,y}]={a,b};
}

pair<int,int> askt(int a,int b) {
	int x=a/N-b/N;
	int y=a%N-b%N;
	if(x>y) swap(x,y);
	return {x,y};
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(A);
	
	if(N==0&&pat.empty()) {
		cin>>N;
	}
	
	for(i=N;i<N*N;i++) {
		for(j=N;j<N*N;j++) if(i!=j) {
			table[i][askt(i,j)]++;
		}
	}
	
	map<pair<int,int>,int> M;
	map<pair<int,int>,vector<int>> P,P2;
	for(i=1;i<N*N-N;i++) {
		auto p=ask(0,i);
		M[p]++;
		P[p].push_back(i);
	}
	
	vector<int> cand;
	for(i=N;i<N*N;i++) {
		if(M==table[i]) cand.push_back(i);
	}
	
	
	int mi=-1,ma=-1;
	if(cand.size()==1) {
		A[0]=cand[0];
		B[0]=A[0]/N+A[0]%N;
	}
	else if(cand.size()==2) {
		assert(cand[0]/N+cand[0]%N==cand[1]/N+cand[1]%N);
		B[0]=cand[0]/N+cand[0]%N;
	}
	else {
		assert(0);
	}
	
	FOR(i,N*N-N) {
		auto p=ask(0,i);
		B[i]=B[0]-(p.first+p.second);
		if(B[i]==1) A[i]=N,mi=i;
		if(B[i]==2*N-2) A[i]=N*N-1,ma=i;
	}
	
	if(A[0]==-1) {
		auto a=ask(0,mi);
		auto b=ask(0,ma);
		for(i=N;i<N*N-N;i++) {
			if(askt(i,N)==a&&askt(i,N*N-1)==b) {
				assert(A[0]==-1);
				A[0]=i;
			}
		}
		assert(A[0]>=0);
	}
	for(j=N;j<N*N;j++) if(j!=A[0]) {
		P2[askt(A[0],j)].push_back(j);
	}
	
	int a=A[0]/N;
	int b=A[0]%N;
	
	FORR(m,P) {
		if(m.second.size()==1) {
			A[m.second[0]]=P2[m.first][0];
		}
		else {
			x=P2[m.first][0];
			y=P2[m.first][1];
			if(askt(x,N*N-1)!=askt(y,N*N-1)) {
				if(ask(m.second[0],ma)==askt(x,N*N-1)) {
					A[m.second[0]]=x;
					A[m.second[1]]=y;
				}
				else {
					A[m.second[0]]=y;
					A[m.second[1]]=x;
				}
			}
			else {
				if(ask(m.second[0],mi)==askt(x,N)) {
					A[m.second[0]]=x;
					A[m.second[1]]=y;
				}
				else {
					A[m.second[0]]=y;
					A[m.second[1]]=x;
				}
			}
			
		}
	}
	
	
	cout<<"!";
	FOR(i,N*N-N) cout<<" "<<A[i];
	cout<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
