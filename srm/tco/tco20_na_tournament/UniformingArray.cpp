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


class UniformingArray {
	public:
	
	int hoge(deque<int>& V,int k) {
		while(V.size()&&V[0]==1) V.pop_front();
		while(V.size()&&V.back()==1) V.pop_back();
		if(V.empty()) return 0;
		
		int cnt=0,i;
		FOR(i,k) {
			if(V.empty()) break;
			if(V.front()==0) cnt++;
			V.pop_front();
			if(cnt*2+1==k) break;
		}
		
		return 1+hoge(V,k);
		
	}
	
	int minOperations(vector <int> A, int k) {
		
		if(*min_element(ALL(A))==1) return 0;
		int mi=1<<20;
		
		int i,x;
		for(i=0;i+k<=A.size();i++) {
			int cnt=0;
			FOR(x,k) cnt+=A[i+x];
			if(cnt*2<k) continue;
			deque<int> L,R;
			for(x=i-1;x>=0;x--) L.push_back(A[x]);
			for(x=i+k;x<A.size();x++) R.push_back(A[x]);
			mi=min(mi,1+hoge(L,k)+hoge(R,k));
		}
		
		if(mi>=1<<20) mi=-1;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; verify_case(0, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(1, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 1, 0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; verify_case(2, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6; verify_case(3, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 11; verify_case(4, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0, 0, 1, 0, 0, 1, 0, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = -1; verify_case(5, Arg2, minOperations(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  UniformingArray ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

