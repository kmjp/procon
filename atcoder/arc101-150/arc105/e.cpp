#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int T;
int N,M;
int win[101010];

class UF {
	public:
	vector<int> par,rank,cnt;
	void reinit(int num) {par=rank=vector<int>(num,0); cnt=vector<int>(num,1); for(int i=0;i<num;i++) par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		uf.reinit(N);
		FOR(i,M) {
			cin>>x>>y;
			x--,y--;
			uf(x,y);
		}
		vector<int> V;
		V.push_back(uf.count(0));
		V.push_back(uf.count(N-1));
		for(i=1;i<N-1;i++) if(uf[i]==i&&uf[i]!=uf[0]&&uf[i]!=uf[N-1]) V.push_back(uf.count(i));
		
		int C[2]={};
		for(i=uf.count(0);i<=N-uf.count(N-1);i++) {
			ll tot=1LL*i*(i-1)/2+1LL*(N-i)*(N-i-1)/2;
			ll add=tot-M;
			win[i]=(add%2)^1;
			C[win[i]]++;
		}
		
		if(C[0]==0) {
			cout<<"Second"<<endl;
		}
		else if(C[1]==0) {
			cout<<"First"<<endl;
		}
		else {
			if(V[0]%2!=V[1]%2) {
				cout<<"First"<<endl;
			}
			else {
				ll a=1LL*N*(N-1)/2-1LL*V[0]*V[1]-M;
				if(a%2==0) {
					cout<<"Second"<<endl;
				}
				else {
					cout<<"First"<<endl;
				}
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
