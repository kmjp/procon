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

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {par=rank=vector<int>(um,0);  for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<2*201010> uf[30];

int T;
int H,W,K,Q;

ll p2[30*201010];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,30*201000) p2[i+1]=p2[i]*2%mo;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K>>Q;
		FOR(i,30) uf[i].reinit(2*(H+W));
		int ng=0;
		int num=(H+W-1)*30;
		
		if(K==0) cout<<p2[num]<<endl;
		
		FOR(i,K+Q) {
			cin>>y>>x>>k;
			y--,x--;
			FOR(j,30) {
				if(k&(1<<j)) {
					if(uf[j][2*y]==uf[j][2*(H+x)+1]) continue;
					num--;
					uf[j](2*y,2*(H+x)+1);
					uf[j](2*y+1,2*(H+x));
					if(uf[j][2*y]==uf[j][2*y+1]) ng=1;
				}
				else {
					if(uf[j][2*y]==uf[j][2*(H+x)]) continue;
					num--;
					uf[j](2*y,2*(H+x));
					uf[j](2*y+1,2*(H+x)+1);
					if(uf[j][2*y]==uf[j][2*y+1]) ng=1;
				}
			}
			
			if(i>=K-1) {
				if(ng) {
					cout<<0<<endl;
				}
				else {
					cout<<p2[num]<<endl;
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
