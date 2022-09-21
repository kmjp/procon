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

int Q;
string S[303030];
ll X[303030],Y[303030];
double D[303030];
int R[303030];
const ll mo=998244353;
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> Xs,Ys;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	vector<double> V;
	FOR(i,Q) {
		cin>>S[i]>>X[i]>>Y[i];
		D[i]=atan2(Y[i],X[i]);
		V.push_back(D[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	int T=V.size();
	double PI=atan(1)*4;
	FOR(i,2*T) V.push_back(V[i]+2*PI);
	FOR(i,T) {
		if(i) R[i]=R[i-1];
		while(V[R[i]]-V[i]<=PI) R[i]++;
	}
	
	ll sum=0;
	FOR(i,Q) {
		x=lower_bound(ALL(V),D[i])-V.begin();
		ll X1=Xs(x+T)-Xs(R[x]-1);
		ll X2=Xs(R[x]-1)-Xs(x);
		ll Y1=Ys(x+T)-Ys(R[x]-1);
		ll Y2=Ys(R[x]-1)-Ys(x);
		
		if(S[i]=="+") {
			sum+=(X1*Y[i]-Y1*X[i]);
			sum-=(X2*Y[i]-Y2*X[i]);
			Xs.add(x,X[i]);
			Xs.add(x+T,X[i]);
			Ys.add(x,Y[i]);
			Ys.add(x+T,Y[i]);
		}
		else {
			sum-=(X1*Y[i]-Y1*X[i]);
			sum+=(X2*Y[i]-Y2*X[i]);
			Xs.add(x,-X[i]);
			Xs.add(x+T,-X[i]);
			Ys.add(x,-Y[i]);
			Ys.add(x+T,-Y[i]);
		}
		sum=(sum%mo+mo)%mo;
		cout<<sum<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
