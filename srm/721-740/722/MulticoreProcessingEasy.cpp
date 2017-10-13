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

class MulticoreProcessingEasy {
	public:
	ll hoge(ll J,ll P,ll S,ll C) {
		ll mi=1LL<<60;
		J=(J+S-1)/S;
		ll L=1;
		ll R=C;
		if(P==0) {
			L=R=C;
		}
		else {
			while(R-L>=10) {
				ll m1=(L*2+R)/3;
				ll m2=(L+R*2)/3;
				ll v1=(m1-1)*P+(J+m1-1)/m1;
				ll v2=(m2-1)*P+(J+m2-1)/m2;
				mi=min({mi,v1,v2});
				if(v1<v2) R=m2;
				if(v1>v2) L=m1;
				if(v1==v2) L=m1,R=m2;
			}
		}
		for(ll i=max(1LL,L-100000);i<=min(C,R+100000);i++) {
			mi=min(mi,(i-1)*P+(J+i-1)/i);
		}
		
		return mi;
		
	}
	int fastestTime(int jobLength, int corePenalty, vector <int> speed, vector <int> cores) {
		ll mi=1LL<<60;
		int i;
		FOR(i,cores.size()) mi=min(mi,hoge(jobLength,corePenalty,speed[i],cores[i]));
		return mi;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2000; int Arg1 = 5; int Arr2[] = {40,20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 30; verify_case(0, Arg4, fastestTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2000; int Arg1 = 5; int Arr2[] = {10,20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 40; verify_case(1, Arg4, fastestTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 0; int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 34; verify_case(2, Arg4, fastestTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10000; int Arg1 = 5; int Arr2[] = {39,37,44}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8,16,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 63; verify_case(3, Arg4, fastestTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MulticoreProcessingEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

