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

class SchedulingWoes {
	public:
	
	int study(int N, int seed, vector <int> Dprefix, int maxD, vector <int> Tprefix, int factor) {
		vector<ll> ran;
		ran.push_back(seed);
		int i;
		for(i=1;i<2*N;i++) {
			ran.push_back((ran.back()*1103515245+12345)%(1LL<<31));
			//cout<<ran[i]<<endl;
		}
		
		vector<pair<ll,ll>> P;
		FOR(i,Dprefix.size()) {
			P.push_back({Dprefix[i],Tprefix[i]});
		}
		for(i=Dprefix.size();i<N;i++) {
			ll D=1+ran[2*i]%maxD;
			ll maxT=max(1LL,D/factor);
			ll T=1+ran[2*i+1]%maxT;
			P.push_back({D,T});
		}
		sort(ALL(P));
		multiset<ll> S;
		ll tot=0;
		FORR(p,P) {
			
			if(p.first-tot>=p.second) {
				S.insert(p.second);
				tot+=p.second;
			}
			else if(S.size() && p.second<*S.rbegin()) {
				tot-=*S.rbegin();
				S.erase(S.find(*S.rbegin()));
				S.insert(p.second);
				tot+=p.second;
			}
		}
		return S.size();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 0; int Arr2[] = {20, 30, 50, 40, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 474747; int Arr4[] = {10, 5, 20, 30, 10}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 474747; int Arg6 = 4; verify_case(0, Arg6, study(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 0; int Arr2[] = {3,1,4,7,2,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 474747; int Arr4[] = {1,1,1,1,1,1,1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 424242; int Arg6 = 7; verify_case(1, Arg6, study(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 0; int Arr2[] = {7,7,7,7,7,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 123456; int Arr4[] = {3,1,4,7,2,5,6}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 654321; int Arg6 = 3; verify_case(2, Arg6, study(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 30; int Arg1 = 47; int Arr2[] = {1000, 2000, 3000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4700; int Arr4[] = {900, 347, 152}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; int Arg6 = 25; verify_case(3, Arg6, study(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SchedulingWoes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

