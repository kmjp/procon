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
int D[202020];
template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
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
UF<202020> uf;

vector<pair<int,int>> ret;
vector<int> cand[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int sum=0;
	FOR(i,N) {
		cin>>D[i];
		sum+=D[i];
	}
	if(sum!=2*(N-1)) {
		cout<<-1<<endl;
		return;
	}
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		D[x]--;
		D[y]--;
		if(uf[x]==uf[y]||D[x]<0||D[y]<0) {
			cout<<"-1"<<endl;
			return;
		}
		uf(x,y);
	}
	FOR(i,N) FOR(j,D[i]) cand[uf[i]].push_back(i);
	priority_queue<pair<int,int>> Q;
	FOR(i,N) if(uf[i]==i) {
		Q.push({(int)cand[i].size(),i});
	}
	while(Q.size()>1) {
		x=Q.top().second;
		Q.pop();
		y=Q.top().second;
		Q.pop();
		if(cand[y].size()==0) {
			cout<<-1<<endl;
			return;
		}
		ret.push_back({cand[x].back()+1,cand[y].back()+1});
		cand[x].pop_back();
		cand[y].pop_back();
		FORR(a,cand[y]) cand[x].push_back(a);
		cand[y].clear();
		Q.push({cand[x].size(),x});
	}
	
	FORR2(a,b,ret) cout<<a<<" "<<b<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
