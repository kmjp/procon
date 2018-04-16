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

bool cmp(pair<ll,ll> a,pair<ll,ll> b) {
	return (a.first*b.second<a.second*b.first);
	
}

class MinimizeAbsoluteDifferenceDiv1 {
	public:
	
	pair<ll,ll> val(ll a,ll b,ll c,ll d) {
		ll p=abs(a*d-b*c);
		ll q=b*d;
		ll g=__gcd(p,q);
		p/=g;
		q/=g;
		return {p,q};
		
	}
	
	vector <int> findTuple(vector <int> x) {
		int a,b,c,d;
		pair<pair<ll,ll>,vector<int>> V;
		pair<ll,ll> p={1000000,1};
		vector<int> R={5,5,5,5};
		FOR(a,5) FOR(b,5) FOR(c,5) FOR(d,5) {
			if(a==b) continue;
			if(a==c) continue;
			if(a==d) continue;
			if(b==c) continue;
			if(b==d) continue;
			if(c==d) continue;
			pair<ll,ll> v=val(x[a],x[b],x[c],x[d]);
			vector<int> A={a,b,c,d};
			if(v==p) R=min(R,A);
			if(cmp(v,p)) R=A, p=v;
		}
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findTuple(Arg0)); }
	void test_case_1() { int Arr0[] = {2,3,5,7,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 1, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findTuple(Arg0)); }
	void test_case_2() { int Arr0[] = {8, 2, 4, 2, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findTuple(Arg0)); }
	void test_case_3() { int Arr0[] = {124, 182, 9, 33, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 3, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findTuple(Arg0)); }
	void test_case_4() { int Arr0[] = {9947, 3, 7, 11, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 4, 3, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findTuple(Arg0)); }
//	void test_case_5() { int Arr0[] = {10000, 4, 10, 4, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, findTuple(Arg0)); }
	void test_case_5() { int Arr0[] = {1, 1, 9997, 9998, 9999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, findTuple(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MinimizeAbsoluteDifferenceDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

