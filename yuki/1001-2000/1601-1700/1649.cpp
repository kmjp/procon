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

int N;
ll X[202020],Y[202020];
const ll mo=998244353;
vector<ll> Xs,Ys;

template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) {ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<ll,20> bit_num,bit_x,bit_y,bit_xy;

vector<int> ev[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	ll xs=0,xs2=0,ys=0,ys2=0;
	Xs.push_back(0);
	Ys.push_back(0);
	
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		
		ret+=xs2;
		ret-=2*xs*X[i];
		ret+=i*((X[i]*X[i])%mo);
		ret+=ys2;
		ret-=2*ys*Y[i];
		ret+=i*((Y[i]*Y[i])%mo);
		ret=(ret%mo+mo)%mo;
		
		(xs+=X[i])%=mo;
		(xs2+=X[i]*X[i])%=mo;
		(ys+=Y[i])%=mo;
		(ys2+=Y[i]*Y[i])%=mo;
		Xs.push_back(X[i]);
		Ys.push_back(Y[i]);
	}
	
	sort(ALL(Xs));
	sort(ALL(Ys));
	FOR(i,N) {
		X[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
		Y[i]=lower_bound(ALL(Ys),Y[i])-Ys.begin();
		ev[X[i]].push_back(i);
	}
	FOR(x,N+1) {
		FORR(i,ev[x]) {
			ll CX=Xs[X[i]];
			ll CY=Ys[Y[i]];
			//ç∂è„
			ret-=2*(bit_xy(N+1)-bit_xy(Y[i]));
			ret-=2*CX*CY%mo*(bit_num(N+1)-bit_num(Y[i]));
			ret+=2*CX%mo*(bit_y(N+1)-bit_y(Y[i]));
			ret+=2*CY%mo*(bit_x(N+1)-bit_x(Y[i]));
			ret=(ret%mo+mo)%mo;
			//ç∂â∫
			ret+=2*bit_xy(Y[i]-1);
			ret+=2*CX*CY%mo*bit_num(Y[i]-1);
			ret-=2*CX%mo*bit_y(Y[i]-1);
			ret-=2*CY%mo*bit_x(Y[i]-1);
			ret=(ret%mo+mo)%mo;
		}
		FORR(i,ev[x]) {
			bit_num.add(Y[i],1);
			bit_x.add(Y[i],Xs[X[i]]);
			bit_y.add(Y[i],Ys[Y[i]]);
			bit_xy.add(Y[i],1LL*Xs[X[i]]*Ys[Y[i]]%mo);
		}
		
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
