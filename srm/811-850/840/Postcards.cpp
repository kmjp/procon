#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

const ll mo=1000000007;
ll A[202020],B[202020];

ll C[402020];
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
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
class Postcards {
	public:
	int count(int N, int Y, int seed) {
		ll state = seed;
		int i;
		UF<402020> uf;
		vector<int> V;
		FOR(i,Y) {
			state = (state * 1103515245 + 12345)%(1LL<<31);
			A[i] = state % N;
			state = (state * 1103515245 + 12345)%(1LL<<31);
			B[i] = state % N;
			V.push_back(A[i]);
			V.push_back(B[i]);
		}
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		ll ret=0;
		ll pat=1LL*N*(N+1)%mo*(2*N+1)%mo*modpow(6)-1LL*N*(N+1)/2%mo;
		pat=(pat%mo+mo)%mo;
		
		
		FOR(i,V.size()) C[i]=V[i]+1;
		FOR(i,Y) {
			ll a=lower_bound(ALL(V),A[i])-V.begin();
			ll b=lower_bound(ALL(V),B[i])-V.begin();
			a=uf[a];
			b=uf[b];
			if(a!=b) {
				pat-=(C[a]*(C[a]-1)+C[b]*(C[b]-1))%mo;
				C[a]=C[b]=(C[a]+C[b])%mo;
				uf(a,b);
				pat+=C[a]*(C[a]-1);
				pat=(pat%mo+mo)%mo;
			}
			ret+=pat%mo;
			
		}
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 1; int Arg2 = 47; int Arg3 = 112; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 1; int Arg2 = 42; int Arg3 = 122; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 2; int Arg2 = 100; int Arg3 = 348; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 20; int Arg2 = 100; int Arg3 = 11942; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 123; int Arg1 = 123; int Arg2 = 123; int Arg3 = 410499337; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Postcards ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

