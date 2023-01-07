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

class ChristmasSongTrauma {
	public:
	double fewest(vector <int> playTime, int visitTime) {
		int N=playTime.size();
		ll sum=0;
		FORR(p,playTime) sum+=p;
		if(visitTime>=sum) return 1;
		int mi=N;
		int i,j;
		FOR(i,N) {
			ll lef=visitTime;
			FOR(j,N) {
				lef-=playTime[(i+j)%N];
				if(lef<=0) break;
			}
			mi=min(mi,j);
		}
		ll tot=0;
		FOR(i,N) {
			ll lef=visitTime;
			FOR(j,N) {
				lef-=playTime[(i+j)%N];
				if(lef<=0) break;
			}
			if(mi==j) {
				if(mi==N-1) lef=-1<<30;
				tot+=min(playTime[i],1+(int)-lef);
			}
		}
		return tot*1.0/sum;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {50, 100, 100, 100, 70, 90, 90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 300; double Arg2 = 0.0016666666666666668; verify_case(0, Arg2, fewest(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 100, 100, 100, 100, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 301; double Arg2 = 1.0; verify_case(1, Arg2, fewest(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {312}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15241235; double Arg2 = 1.0; verify_case(2, Arg2, fewest(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {50, 100, 100, 100, 70, 90, 90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 310; double Arg2 = 0.41; verify_case(3, Arg2, fewest(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChristmasSongTrauma ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

