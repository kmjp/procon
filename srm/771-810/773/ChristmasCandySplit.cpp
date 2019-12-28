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

class ChristmasCandySplit {
	public:
	vector<long long> buyMoreBags(vector <int> B) {
		int N=B.size();
		
		ll A=1;
		int i;
		set<ll> did;
		vector<ll> ret;
		ll sum=0;
		for(i=1;i<=22;i++) {
			A=A/__gcd(A,(ll)i)*i;
			did.insert(i);
			if(count(ALL(B),i)==0) ret.push_back(i);
			sum+=i;
		}
		
		vector<ll> cand;
		for(ll a=1;a*a<=A;a++) if(A%a==0) cand.push_back(a),cand.push_back(A/a);
		sort(ALL(cand));
		reverse(ALL(cand));
		FORR(c,cand) if(did.count(c)==0 && sum+c<=A) {
			ret.push_back(c);
			sum+=c;
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {2, 6, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {24, 36, 72, 144 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, buyMoreBags(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {6 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, buyMoreBags(Arg0)); }
	void test_case_2() { int Arr0[] = {10, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {2, 30, 6 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, buyMoreBags(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChristmasCandySplit ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

