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

class Flagpole {
	public:
	ll hoge(vector<int> S,ll v) {
		int A=S.size()/2;
		int B=S.size()-A;
		
		vector<ll> C;
		int i,mask;
		FOR(mask,1<<B) {
			ll sum=0;
			FOR(i,B) if(mask&(1<<i)) sum+=S[i];
			C.push_back(sum);
		}
		sort(ALL(C));
		ll ret=0;
		FOR(mask,1<<A) {
			ll sum=0;
			FOR(i,A) if(mask&(1<<i)) sum+=S[i+B];
			ret+=lower_bound(ALL(C),v-sum+1)-C.begin();
		}
		return ret;
		
	}
	
	long long build(vector <int> segments, long long LO, long long HI) {
		return hoge(segments,HI)-hoge(segments,LO);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; long long Arg2 = 49LL; long long Arg3 = 30LL; verify_case(0, Arg3, build(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {10, 10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 30LL; long long Arg2 = 39LL; long long Arg3 = 0LL; verify_case(1, Arg3, build(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 4, 8, 16, 32, 64, 128}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 47LL; long long Arg2 = 100LL; long long Arg3 = 53LL; verify_case(2, Arg3, build(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {50, 10, 40, 30, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 45LL; long long Arg2 = 63LL; long long Arg3 = 6LL; verify_case(3, Arg3, build(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Flagpole ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

