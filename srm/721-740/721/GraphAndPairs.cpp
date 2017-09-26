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

class GraphAndPairs {
	public:
	vector<int> hoge2(int K) {
		vector<int> R;
		R.push_back(0);
		int num=0;
		int i,j;
		while(K) {
			for(int i=1000;i>=1;i--) {
				if(i*(i-1)/2<=K) {
					FOR(j,i) R.push_back(num),R.push_back(num+1+j);
					num+=i+1;
					K-=i*(i-1)/2;
					break;
				}
			}
		}
		R[0]=num;
		return R;
		
	}
	
	vector <int> construct(int D, int K) {
		if(D==2) return hoge2(K);
		vector<int> R;
		R.push_back(0);
		int num=0;
		int i,j;
		while(K) {
			FOR(i,D-2) R.push_back(num+i),R.push_back(num+i+1);
			int LL=num;
			int RR=num+D-2;
			num+=D-1;
			
			for(int i=1000;i>=1;i--) {
				if(i*i<=K) {
					FOR(j,i) R.push_back(LL),R.push_back(num+j);
					FOR(j,i) R.push_back(RR),R.push_back(num+i+j);
					
					num+=2*i;
					K-=i*i;
					break;
				}
				if(i*(i-1)<=K) {
					FOR(j,i) R.push_back(LL),R.push_back(num+j);
					FOR(j,i-1) R.push_back(RR),R.push_back(num+i+j);
					
					num+=2*i-1;
					K-=i*(i-1);
					break;
				}
				
			}
		}
		R[0]=num;
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arr2[] = {4, 0, 1, 1, 3, 3, 2, 2, 0, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {8, 0, 1, 1, 3, 3, 2, 2, 0, 1, 2, 4, 5, 5, 7, 7, 6, 6, 4, 5, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arr2[] = {8, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, construct(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {10, 0, 1, 1, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8, 8, 9, 0, 5, 1, 6, 2, 7, 3, 8, 4, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GraphAndPairs ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

