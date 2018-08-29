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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

int N,M;
int X[101010],Y[101010];
vector<pair<int,int>> V;
vector<int> Ys;
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>X[i];
	FOR(i,M) cin>>Y[i];
	Ys.push_back(0);
	FOR(i,N) {
		if(X[i]<Y[0]) continue;
		if(X[i]>Y[M-1]) continue;
		x=lower_bound(Y,Y+M,X[i])-Y;
		V.push_back({X[i]-Y[x-1],-(Y[x]-X[i])});
		Ys.push_back(Y[x]-X[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	sort(ALL(Ys));
	Ys.erase(unique(ALL(Ys)),Ys.end());
	bt.add(0,1);
	FORR(v,V) {
		y=lower_bound(ALL(Ys),-v.second)-Ys.begin();
		bt.add(y,bt(y-1)%mo);
	}
	
	cout<<bt(Ys.size()+2)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
