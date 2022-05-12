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

class SnookerScoring {
	public:
	vector <int> scoreN(int N, int R, int C) {
		vector<int> V;
		int i,j,x;
		for(i=1;i<=R;i++) {
			{
				int mi=i+2*(i-1);
				int ma=i+(C+1)*(i-1);
				if(mi<=N&&N<=ma) {
					FOR(j,i) {
						V.push_back(1);
						V.push_back(2);
					}
					V.pop_back();
					N-=i*3-2;
					FOR(j,i-1) {
						int x=min(C-1,N);
						V[j*2+1]+=x;
						N-=x;
					}
					return V;
				}
			}
			{
				int mi=i+2*i;
				int ma=i+(C+1)*i;
				if(mi<=N&&N<=ma) {
					N-=i*3;
					FOR(j,i) {
						V.push_back(1);
						V.push_back(2);
					}
					FOR(j,i) {
						int x=min(C-1,N);
						V[j*2+1]+=x;
						N-=x;
					}
					return V;
				}
			}
		}
		
		for(i=0;i<=R;i++) {
			int mi=i+2*i;
			int ma=i+(C+1)*i;
			int sum=0;
			for(x=2;x<=C+1;x++) {
				sum+=x;
				if(mi+sum<=N&&N<=ma+sum) {
					N-=sum;
					FOR(j,i) {
						V.push_back(1);
						V.push_back(2);
					}
					N-=i*3;
					FOR(j,i) {
						int x=min(C-1,N);
						V[j*2+1]+=x;
						N-=x;
					}
					for(i=2;i<=x;i++) V.push_back(i);
					return V;
				}
			}
		}
		
		
		
		
		
		return V;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 51; int Arg1 = 15; int Arg2 = 6; int Arr3[] = {1, 7, 1, 7, 1, 7, 2, 3, 4, 5, 6, 7 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, scoreN(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 15; int Arg2 = 6; int Arr3[] = {3, 4, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, scoreN(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 15; int Arg2 = 6; int Arr3[] = {1, 2, 2, 3, 4, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, scoreN(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 16; int Arg1 = 15; int Arg2 = 6; int Arr3[] = {1, 7, 1, 6, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, scoreN(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 45; int Arg1 = 10; int Arg2 = 2; int Arr3[] = {1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 2, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, scoreN(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SnookerScoring ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

