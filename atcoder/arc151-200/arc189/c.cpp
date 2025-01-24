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

int N,X;
int A[202020],B[202020],P[202020],Q[202020];
int RP[202020],RQ[202020];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<202020> uf[2];

#include <limits>
template<class CC> int LIS_num(vector<CC>& v) {
	int i,N=v.size();
	if(v.empty()) return 0;
	vector<CC> dp(N,(numeric_limits<CC>::max)()),id(N);
	FOR(i,v.size()) dp[id[i]=lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin()] = v[i];
	// FOR(i,v.size()) dp[id[i]=lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin()] = v[i]-1; “¯‚¶”’l‚Ì˜A‘±‚à‹–‰Â‚·‚éê‡
	return *max_element(id.begin(),id.end())+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	X--;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
		uf[0](i,P[i]);
		RP[P[i]]=i;
	}
	FOR(i,N) {
		cin>>Q[i];
		Q[i]--;
		uf[1](i,Q[i]);
		RQ[Q[i]]=i;
	}
	FOR(i,N) {
		if(A[i]&&uf[0][i]!=uf[0][X]) {
			cout<<-1<<endl;
			return;
		}
		if(B[i]&&uf[1][i]!=uf[1][X]) {
			cout<<-1<<endl;
			return;
		}
	}
	vector<int> Xs={X},Ys={X};
	while(RP[Xs.back()]!=X) Xs.push_back(RP[Xs.back()]);
	while(RQ[Ys.back()]!=X) Ys.push_back(RQ[Ys.back()]);
	while(Xs.size()>1&&A[Xs.back()]==0) Xs.pop_back();
	while(Ys.size()>1&&B[Ys.back()]==0) Ys.pop_back();
	reverse(ALL(Xs));
	reverse(ALL(Ys));
	Xs.pop_back();
	Ys.pop_back();
	set<int> C;
	int ret=Xs.size()+Ys.size();
	map<int,int> M;
	x=0;
	FORR(a,Xs) {
		M[a]=x++;
	}
	vector<int> V;
	FORR(a,Ys) if(M.count(a)) V.push_back(M[a]);
	ret-=LIS_num(V);
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
