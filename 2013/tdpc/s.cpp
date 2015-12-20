#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

ll mo=1000000007;
ll dp[105][1<<12];
int table[1<<12][1<<6];
int H,W;

int calctable(int m1,int m2) {
	int x,y,i;
	int mi[12]={};
	UF<12> uf;
	FOR(y,6) {
		i=(m1>>(y*2))&3;
		if(i==0) mi[y]=20;
		else mi[y]=i-1;
		
		if(m2&(1<<y)) mi[y+6]=10+y;
		else mi[y+6]=20;
	}
	FOR(y,6) {
		if(y && mi[y]<20 && mi[y-1]<20) uf(y,y-1);
		if(y && mi[y+6]<20 && mi[y-1+6]<20) uf(y+6,y-1+6);
		if(mi[y]<20 && mi[y+6]<20) uf(y,6+y);
	}
	FOR(y,6) FOR(x,y) if(mi[x]==mi[y]) uf(x,y);
	
	vector<int> v;
	FOR(y,12) mi[uf[y]]=min(mi[uf[y]],mi[y]);
	FOR(y,6) if(mi[uf[y+6]]<20) v.push_back(mi[uf[y+6]]);
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	if(v.empty() || v[0]!=0) return -1;
	
	int ret=0;
	FOR(y,6) {
		if(mi[uf[y+6]]==20) x=0;
		else x=lower_bound(ALL(v),mi[uf[y+6]])-v.begin()+1;
		ret |= x<<(2*y);
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	dp[0][1]=1;
	cin>>H>>W;
	FOR(i,1<<(2*H)) FOR(j,1<<H) table[i][j]=calctable(i,j);
	
	FOR(x,W) {
		FOR(i,1<<(2*H)) if(dp[x][i]) {
			FOR(j,1<<H) if(table[i][j]>=0) {
				dp[x+1][table[i][j]] += dp[x][i];
				if(dp[x+1][table[i][j]]>=mo) dp[x+1][table[i][j]]-=mo;
			}
		}
	}
	ll ret=0;
	FOR(i,1<<(2*H)) if(((i>>(2*(H-1)))&3)==1) ret += dp[W][i];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
