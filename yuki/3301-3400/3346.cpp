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
vector<int> E[303030];
vector<int> Ds[303030];
int D[303030];
const ll mo=998244353;
ll p2[303030];

int dfs(int cur,int pre) {
	Ds[cur].push_back(0);
	FORR(e,E[cur]) if(e!=pre) {
		Ds[cur].push_back(dfs(e,cur)+1);
		D[cur]=max(D[cur],Ds[cur].back());
	}
	return D[cur];
}

void dfs2(int cur,int pre,int par) {
	if(cur) Ds[cur].push_back(par);
	sort(ALL(Ds[cur]));
	reverse(ALL(Ds[cur]));
	FORR(e,E[cur]) if(e!=pre) {
		if(Ds[cur][0]==D[e]+1) dfs2(e,cur,Ds[cur][1]+1);
		else dfs2(e,cur,Ds[cur][0]+1);
	}
}

vector<int> norm(vector<int> A) {
	map<int,int> B;
	FORR(a,A) B[a]++;
	vector<int> C;
	while(B.size()) {
		int b1=B.begin()->first;
		int b2=B.begin()->second;
		B.erase(B.begin());
		if(b2>=2) B[b1+1]+=b2/2;
		if(b2%2) C.push_back(b1);
	}
	reverse(ALL(C));
	return C;
}

vector<int> hoge(vector<int> A,vector<int> B) {
	if(A.empty()) return B;
	int a1=A[0],a2=A[1],a3=A[2];
	int AS=a1+a2+a3;
	int b1=B[0],b2=B[1],b3=B[2];
	int BS=b1+b2+b3;
	
	vector<int> As={
		a1+1+BS,
		a2+1+BS,
		a3+1+BS,
		AS+1,
		AS
	};
	vector<int> Bs={
		b1+1+AS,
		b2+1+AS,
		b3+1+AS,
		BS+1,
		BS
	};
	As=norm(As);
	Bs=norm(Bs);
	if(As<Bs) return A;
	return B;
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	p2[0]=1;
	FOR(i,N+10) p2[i+1]=p2[i]*2%mo;
	
	dfs(0,0);
	dfs2(0,0,0);
	vector<int> vec;
	FOR(i,N) if(E[i].size()>=2) {
		vector<int> W={Ds[i][0],Ds[i][1],Ds[i][2]};
		vec=hoge(vec,W);
	}
	
	int K=vec[0]+vec[1]+vec[2];
	ll ret=p2[N+2]-p2[N-K]*(p2[vec[0]+1]+p2[vec[1]+1]+p2[vec[2]+1]-3)%mo;
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
