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

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class FalseAbove {
	public:
	vector <int> solve(int N) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
		
		ll L=N/2;
		ll R=N/2+1;
		ll M=N+1;
		ll pat=0;
		ll spat=0;
		int i;
		if(N%2==0) {
			pat=fact[L];
			ll sum=1LL*(N/2+1+N)*(N/2)/2%mo;
			for(i=0;i<N;i+=2) {
				spat+=sum*modpow(M,i)%mo*fact[L-1]%mo;
			}
			for(i=1;i<N;i+=2) {
				spat+=(i+1)/2*pat%mo*modpow(M,i)%mo;
			}
		}
		else {
			
			// _1_2_3_4_
			pat=fact[R];
			ll sum=1LL*(N/2+1+N)*(N-L)/2%mo;
			for(i=0;i<N;i+=2) {
				spat+=sum*modpow(M,i)%mo*fact[L]%mo;
			}
			for(i=1;i<N;i+=2) {
				spat+=(i+1)/2*fact[R]%mo*modpow(M,i)%mo;
			}
			
			
			//_1_2_3__5
			//_1_2__4_5
			//_1__3_4_5
			//__2_3_4_5
			ll w=0;
			FOR(i,N) {
				if(i&&i%2==0) continue;
				w+=modpow(M,i);
			}
			w%=mo;
			ll usum=1LL*(R+1+N)*(N-R)/2%mo;
			ll LS=0,RS=0;
			for(i=2;i<=R;i++) (RS+=i*modpow(M,i*2-2))%=mo;
			for(i=1;i<=L;i++) {
				pat+=L*fact[L]%mo;
				spat+=(L*fact[L-1]%mo)*usum%mo*modpow(M,i*2-1)%mo;
				spat+=((L-1)*fact[L-1]%mo)*usum%mo*(w-modpow(M,i*2-1)+mo)%mo;
				spat+=(fact[L]%mo)*i%mo*(w-modpow(M,i*2-1)+mo)%mo;
				spat+=(LS+RS)*L%mo*fact[L]%mo;
				
				w=(w-modpow(M,i*2-1)+modpow(M,i*2)+mo)%mo;
				(LS+=i*modpow(M,i*2-1)%mo)%=mo;
				(RS+=mo-(i+1)*modpow(M,i*2)%mo)%=mo;
				
			}
			
			
		}
		
		
		return {(int)L,(int)(pat%mo),(int)(spat%mo)};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1, 1, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1, 3, 138 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {3, 6, 380214 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, solve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FalseAbove ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

