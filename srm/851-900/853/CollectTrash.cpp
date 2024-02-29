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

class CollectTrash {
	public:
	int optimize(int P, int T, int M, int C, vector <int> Lprefix, int seed) {
		ll state=seed;
		int PL=Lprefix.size();
		vector<ll> L;
		FORR(a,Lprefix) L.push_back(a);
		
		int i;
		for(i=PL;i<T;i++) {
			if(C==1&&i) {
				state = (state * 1103515245 + 12345) % (1LL<<31);
		        ll old = L[state%i];
				state = (state * 1103515245 + 12345) % (1LL<<31);
		        ll spread = (state%21)-10;
		        L.push_back(max(0LL, min(M-1LL, old+spread)));
		    }
		    else {
				state = (state * 1103515245 + 12345) % (1LL<<31);
		        L.push_back(state%M);
		    }
		}
		sort(ALL(L));
		ll ret=1LL<<60;
		for(i=59;i>=0;i--) {
			ll tmp=ret-(1LL<<i);
			ll num=0;
			ll cur=L.size()-1;
			while(cur>=0) {
				num++;
				ll lef=tmp-(L[cur]+1);
				if(lef<0) break;
				cur-=lef+1;
			}
			if(cur<0&&num<=P) ret=tmp;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 1000000000; int Arg3 = 0; int Arr4[] = {7, 4, 10, 4}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1000000000; int Arg6 = 14; verify_case(0, Arg6, optimize(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 47; int Arg1 = 47003; int Arg2 = 1; int Arg3 = 0; int Arr4[] = {}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 47; int Arg6 = 1001; verify_case(1, Arg6, optimize(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 100000; int Arg3 = 0; int Arr4[] = {1, 2, 3, 4, 5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 42; int Arg6 = 7; verify_case(2, Arg6, optimize(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 12; int Arg2 = 7654321; int Arg3 = 0; int Arr4[] = {1000, 2000, 3000}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1234567; int Arg6 = 5937965; verify_case(3, Arg6, optimize(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 12; int Arg2 = 7654321; int Arg3 = 1; int Arr4[] = {1000, 2000, 3000}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1234567; int Arg6 = 3015; verify_case(4, Arg6, optimize(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CollectTrash ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

