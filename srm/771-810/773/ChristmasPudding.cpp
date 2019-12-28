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

class ChristmasPudding {
	public:
	long long eat(int N, long long Vall, long long Vsweet, vector <int> V, vector <int> T, vector <int> S, int seed) {
		ll state=seed;
		while(V.size()<N) {
			state = (state * 1103515245 + 12345) % (1LL<<31);
			V.push_back(1+state%1000000);
			state = (state * 1103515245 + 12345) % (1LL<<31);
			T.push_back(1+state%1000000);
			state = (state * 1103515245 + 12345) % (1LL<<31);
			S.push_back(state/1024%2);
		}
		
		vector<pair<int,int>> A,B;
		int i;
		FOR(i,S.size()) {
			if(S[i]==0) {
				A.push_back({T[i],V[i]});
			}
			else {
				B.push_back({T[i],V[i]});
			}
		}
		sort(ALL(A));
		sort(ALL(B));
		ll ret=0;
		while(Vsweet>0 && B.size()) {
			ll a=min(Vsweet,(ll)B.back().second);
			B.back().second-=a;
			Vsweet-=a;
			Vall-=a;
			ret+=B.back().first*a;
			if(B.back().second==0) B.pop_back();
		}
		while(Vall && A.size()+B.size()) {
			if(B.empty()) {
				goa:
				ll a=min(Vall,(ll)A.back().second);
				A.back().second-=a;
				Vall-=a;
				ret+=A.back().first*a;
				if(A.back().second==0) A.pop_back();
			}
			else if(A.empty()) {
				gob:
				ll a=min(Vall,(ll)B.back().second);
				B.back().second-=a;
				Vall-=a;
				ret+=B.back().first*a;
				if(B.back().second==0) B.pop_back();
			}
			else if(A.back().first<B.back().first) {
				goto gob;
			}
			else {
				goto goa;
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 300LL; long long Arg2 = 220LL; int Arr3[] = {100, 100, 200}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {4, 5, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1, 0, 1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 47; long long Arg7 = 1880LL; verify_case(0, Arg7, eat(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 390LL; long long Arg2 = 220LL; int Arr3[] = {100, 100, 200}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {4, 5, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1, 0, 1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 4747; long long Arg7 = 2260LL; verify_case(1, Arg7, eat(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 300LL; long long Arg2 = 300LL; int Arr3[] = {100, 200, 300}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {30, 10, 20}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 1, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 42; long long Arg7 = 5000LL; verify_case(2, Arg7, eat(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 2; long long Arg1 = 100LL; long long Arg2 = 0LL; int Arr3[] = {47, 10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {3, 5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 5; long long Arg7 = 191LL; verify_case(3, Arg7, eat(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 20; long long Arg1 = 5000000LL; long long Arg2 = 3000000LL; int Arr3[] = {470}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {407}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 4747; long long Arg7 = 3528114042726LL; verify_case(4, Arg7, eat(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_5() { int Arg0 = 10; long long Arg1 = 0LL; long long Arg2 = 0LL; int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 0; long long Arg7 = 0LL; verify_case(5, Arg7, eat(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChristmasPudding ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

