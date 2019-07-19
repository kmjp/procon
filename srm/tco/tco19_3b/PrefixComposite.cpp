#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class PrefixComposite {
	public:
	ll p10[13];
	
	bool isprime(ll v) {
		if(v==1) return 1;
		for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
		return (v!=1);
	}
	
	ll getmore(ll v) {
		vector<ll> V;
		ll w=v;
		while(w) {
			V.push_back(w);
			w/=10;
		}
		reverse(ALL(V));
		int i;
		FOR(i,V.size()) if(isprime(V[i])) {
			return getmore((V[i]+1)*p10[V.size()-1-i]);
		}
		return v;
		
	}
	ll getless(ll v) {
		if(v<=3) return -1;
		vector<ll> V;
		ll w=v;
		while(w) {
			V.push_back(w);
			w/=10;
		}
		reverse(ALL(V));
		int i;
		FOR(i,V.size()) if(isprime(V[i])) {
			ll nv=V[i]*p10[V.size()-1-i];
			if(nv<v) return getless(nv);
			else return getless(nv-1);
		}
		return v;
	}
	
	vector<long long> minMax(long long A, long long B) {
		p10[0]=1;
		int i;
		FOR(i,12) p10[i+1]=p10[i]*10;
		
		ll a = getmore(A);
		ll b = getless(B);
		
		
		
		if(a>b) return {};
		return {a,b};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 3LL; long Arr2[] = { }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, minMax(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 4LL; long Arr2[] = {4, 4 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, minMax(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 123LL; long long Arg1 = 838LL; long Arr2[] = {400, 828 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, minMax(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 409LL; long long Arg1 = 87343LL; long Arr2[] = {420, 87343 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, minMax(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 979797LL; long long Arg1 = 979898LL; long Arr2[] = { }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, minMax(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 600LL; long long Arg1 = 703LL; long Arr2[] = {600, 699 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, minMax(Arg0, Arg1)); }
	void test_case_6() { long long Arg0 = 1LL; long long Arg1 = 100000000000LL; long Arr2[] = {4, 99999999999 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, minMax(Arg0, Arg1)); }
	void test_case_7() { long long Arg0 = 37337999LL; long long Arg1 = 37337999LL; long Arr2[] = { }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(7, Arg2, minMax(Arg0, Arg1)); }
	void test_case_8() { long long Arg0 = 22LL; long long Arg1 = 39LL; long Arr2[] = { }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(8, Arg2, minMax(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PrefixComposite ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

