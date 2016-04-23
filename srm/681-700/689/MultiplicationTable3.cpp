#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class MultiplicationTable3 {
	public:
	int check(vector <int> v)  {
		int N=1;
		int ret=0,x,y;
		while(N*N<v.size()) N++;
		for(int mask=1;mask<1<<N;mask++) {
			int ok=1;
			FOR(y,N) if(mask&(1<<y)) FOR(x,N) if(mask&(1<<x)) if((mask & (1<<v[y*N+x]))==0) ok=0;
			ret+=ok;
		}
		return ret;
	}
	vector <int> construct(int X) {
		int y=X+1;
		vector<int> V,R;
		int i,x;
		for(i=10;i>=0;i--) if(y&(1<<i)) V.push_back(i);
		int sz=V[0]+V.size()-1;
		
		R.resize(sz*sz);
		
		FOR(i,V[0]) FOR(x,sz) R[i*sz+x]=x;
		int cur=V[0];
		for(i=1;i<V.size();i++) {
			FOR(x,sz) {
				if(x==cur) R[cur*sz+x]=V[i];
				else if(x>=cur || x<V[i]) R[cur*sz+x]=x;
				else R[cur*sz+x]=x+1;
			}
			cur++;
		}
		
		//assert(check(R)==X);
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1, 1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0, 1, 0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {0, 1, 1, 0, 1, 2, 0, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arg0 = 31; int Arr1[] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, construct(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MultiplicationTable3 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
