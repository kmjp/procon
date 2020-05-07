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

int N,Q;
ll X[101010],Y[101010],D[101010],C[101010];
int AX[101010],AY[101010];
vector<ll> Ys;
vector<pair<int,int>> ev;

//Ç≥ÇÁÇ…íZèk
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;
ll ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>D[i]>>C[i];
		Ys.push_back(Y[i]);
		Ys.push_back(Y[i]+D[i]);
		ev.push_back({X[i],i});
		ev.push_back({X[i]+D[i],N+Q+i});
	}
	FOR(i,Q) {
		cin>>AX[i]>>AY[i];
		Ys.push_back(AY[i]);
		ev.push_back({AX[i],i+N});
	}
	Ys.push_back(-1<<30);
	sort(ALL(Ys));
	sort(ALL(ev));
	FORR(e,ev) {
		x=e.second;
		if(x<N || x>=N+Q) {
			if(x>=N+Q) x-=N+Q;
			int y1=lower_bound(ALL(Ys),Y[x])-Ys.begin();
			int y2=lower_bound(ALL(Ys),Y[x]+D[x])-Ys.begin();
			if(e.second<N) bt.add(y1,C[x]),bt.add(y2+1,-C[x]);
			else bt.add(y1,-C[x]),bt.add(y2+1,C[x]);
		}
		else {
			x-=N;
			y=lower_bound(ALL(Ys),AY[x])-Ys.begin();
			ret[x]=bt(y);
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
