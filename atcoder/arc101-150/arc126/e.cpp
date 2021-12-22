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

int N,Q;
ll A[303030];
const ll mo=998244353;
ll X[606060],Y[303030];

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
BIT<ll,21> num,sum;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	vector<ll> Vs;
	FOR(i,N) {
		cin>>A[i];
		A[i]=(A[i]<<30)+i;
		Vs.push_back(A[i]);
	}
	FOR(i,Q) {
		cin>>X[i]>>Y[i];
		X[i]--;
		Y[i]=(Y[i]<<30)+N+i;
		Vs.push_back(Y[i]);
	}
	
	sort(ALL(Vs));
	Vs.erase(unique(ALL(Vs)),Vs.end());
	
	FOR(i,N) {
		A[i]=lower_bound(ALL(Vs),A[i])-Vs.begin();
		num.add(A[i],1);
		sum.add(A[i],Vs[A[i]]>>30);
	}
	ll tsum=0;
	FOR(i,N) {
		x=num(A[i]);
		y=Vs[A[i]]>>30;
		tsum+=1LL*(x-1)*y%mo;
		tsum-=1LL*(N-x)*y%mo;
	}
	FOR(i,Q) {
		x=X[i];
		y=Vs[A[x]]>>30;
		k=num(A[x]);
		tsum-=1LL*(k-1)*y%mo;
		tsum+=1LL*(N-k)*y%mo;
		tsum+=sum(A[x]-1)%mo;
		tsum-=(sum(1<<20)-sum(A[x]))%mo;
		num.add(A[x],-1);
		sum.add(A[x],-y);
		
		A[x]=lower_bound(ALL(Vs),Y[i])-Vs.begin();
		y=Vs[A[x]]>>30;

		num.add(A[x],1);
		sum.add(A[x],y);

		k=num(A[x]);
		tsum+=1LL*(k-1)*y%mo;
		tsum-=1LL*(N-k)*y%mo;
		tsum-=sum(A[x]-1)%mo;
		tsum+=(sum(1<<20)-sum(A[x]))%mo;
		tsum=(tsum%mo+mo)%mo;
		cout<<tsum*(mo+1)/2%mo<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
