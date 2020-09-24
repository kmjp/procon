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

vector<int> Xs;
vector<int> Ys;
class EllysDiggyDiggyHole {
	public:
	long long getMin(int N, int M, int X1, int Y1, int A, int B, int C, int D) {
		Xs.clear();
		Ys.clear();
		Xs.push_back(X1);
		Ys.push_back(Y1);
		while(Xs.size()<N) {
			Xs.push_back(((ll)Xs.back()*A+B)&(M-1));
			Ys.push_back(((ll)Ys.back()*C+D)&(M-1));
		}
		nth_element(Xs.begin(),Xs.begin()+(N/2),Xs.end());
		nth_element(Ys.begin(),Ys.begin()+(N/2),Ys.end());
		//sort(ALL(Xs));
		//sort(ALL(Ys));
		int cx=Xs[N/2];
		int cy=Ys[N/2];
		ll sum=0;
		int i;
		cout<<cx<<" "<<cy<<endl;
		FOR(i,N) sum+=abs(Xs[i]-cx)+abs(Ys[i]-cy);
		return sum;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 16; int Arg2 = 5; int Arg3 = 10; int Arg4 = 13; int Arg5 = 1; int Arg6 = 5; int Arg7 = 5; long long Arg8 = 42LL; verify_case(0, Arg8, getMin(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 128; int Arg2 = 34; int Arg3 = 39; int Arg4 = 5; int Arg5 = 96; int Arg6 = 80; int Arg7 = 13; long long Arg8 = 666LL; verify_case(1, Arg8, getMin(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 1048576; int Arg2 = 699552; int Arg3 = 791661; int Arg4 = 501611; int Arg5 = 673171; int Arg6 = 220299; int Arg7 = 769494; long long Arg8 = 50901268LL; verify_case(2, Arg8, getMin(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 1234567; int Arg1 = 16777216; int Arg2 = 42; int Arg3 = 13; int Arg4 = 1337; int Arg5 = 666; int Arg6 = 17; int Arg7 = 69; long long Arg8 = 10358982811846LL; verify_case(3, Arg8, getMin(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysDiggyDiggyHole ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

