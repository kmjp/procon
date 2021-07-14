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

int N,M,Q;
int T[202020],X[202020],Y[202020];
vector<int> V;
int A[202020],B[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<ll,20> Anum,Asum,Bnum,Bsum;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	V.push_back(0);
	cin>>N>>M>>Q;
	FOR(i,Q) {
		cin>>T[i]>>X[i]>>Y[i];
		X[i]--;
		V.push_back(Y[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	Anum.add(0,N);
	Bnum.add(0,M);
	ll sum=0;
	FOR(i,Q) {
		Y[i]=lower_bound(ALL(V),Y[i])-V.begin();
		if(T[i]==1) {
			//del
			x=A[X[i]];
			sum-=Bnum(x)*V[x];
			sum+=Bsum(x);
			Anum.add(x,-1);
			Asum.add(x,-V[x]);
			//add
			x=A[X[i]]=Y[i];
			sum+=Bnum(x)*V[x];
			sum-=Bsum(x);
			Anum.add(x,1);
			Asum.add(x,V[x]);
		}
		else {
			//del
			x=B[X[i]];
			sum-=Anum(x)*V[x];
			sum+=Asum(x);
			Bnum.add(x,-1);
			Bsum.add(x,-V[x]);
			//add
			x=B[X[i]]=Y[i];
			sum+=Anum(x)*V[x];
			sum-=Asum(x);
			Bnum.add(x,1);
			Bsum.add(x,V[x]);
		}
		cout<<sum<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
