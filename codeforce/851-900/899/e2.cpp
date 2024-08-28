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
int A[2525],B[2525];
vector<int> X[10101];
vector<int> Y[10101];

vector<int> hoge(vector<int> T,int X) {
	int A[2525],R[2525];
	int i,j;
	FOR(i,T.size()) {
		A[i]=(T[i]+X)%T.size();
		R[A[i]]=i;
	}
	vector<int> ret;
	int cur=0;
	while(A[X]!=X) {
		int x=R[cur];
		ret.push_back((x-cur+T.size())%T.size());
		swap(A[x],A[cur]);
		R[A[cur]]=cur;
		R[A[x]]=x;
		swap(cur,x);
	}
	
	FOR(i,T.size()) if(A[i]!=i) {
		ret.push_back((i-X+T.size())%T.size());
		swap(A[i],A[X]);
		R[A[i]]=i;
		R[A[X]]=X;
		int cur=i;
		while(A[X]!=X) {
			int x=R[cur];
			ret.push_back((x-cur+T.size())%T.size());
			swap(A[x],A[cur]);
			R[A[cur]]=cur;
			R[A[x]]=x;
			swap(cur,x);
		}
	}
	return ret;
		
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,M) cin>>B[i];
	X[0]=Y[0]={1};
	
	FOR(i,N+1) {
		vector<int> Z={0};
		FOR(j,N) Z.push_back(A[j]);
		auto a=hoge(Z,i);
		X[a.size()]=a;
	}
	FOR(i,M+1) {
		vector<int> Z={0};
		FOR(j,M) Z.push_back(B[j]);
		auto a=hoge(Z,i);
		Y[a.size()]=a;
	}
	
	if(X[0].empty()&&Y[0].empty()) {
		cout<<0<<endl;
		return;
	}
	if(X[0].empty()) {
		X[2]={1,N};
		X[N].clear();
		FOR(i,N) X[N].push_back(1);
	}
	if(Y[0].empty()) {
		Y[2]={1,M};
		Y[M].clear();
		FOR(i,M) Y[M].push_back(1);
	}
	
	const int ma=5000;
	for(i=1;i<=ma;i++) {
		if(X[i].size()&&Y[i].size()) {
			cout<<i<<endl;
			FOR(j,i) cout<<X[i][j]<<" "<<Y[i][j]<<endl;
			return;
		}
		if(X[i].size()&&X[i+2].empty()) {
			X[i+2]=X[i];
			X[i+2].push_back(1);
			X[i+2].push_back(N);
		}
		if(Y[i].size()&&Y[i+2].empty()) {
			Y[i+2]=Y[i];
			Y[i+2].push_back(1);
			Y[i+2].push_back(M);
		}
		if(X[i].size()&&i+N<=ma&&X[i+N].empty()) {
			X[i+N]=X[i];
			FOR(j,N) X[i+N].push_back(1);
		}
		if(Y[i].size()&&i+M<=ma&&Y[i+M].empty()) {
			Y[i+M]=Y[i];
			FOR(j,M) Y[i+M].push_back(1);
		}
	}
	
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
