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

class FixedPointReversals {
	public:
	vector<int> C;
	vector<int> ret;
	void goswap(int a,int b) {
		ret.push_back(a);
		ret.push_back(b+1);
		reverse(C.begin()+a,C.begin()+b+1);
	}
	vector <int> sort(vector <int> A, int F) {
		int N=A.size();
		vector<int> B=A;
		C.resize(N);
		ret.clear();
		
		std::sort(ALL(B));
		if(A[F]!=B[F]) return {-1};
		
		int x,y,i;
		C[F]=F;
		FOR(x,N) if(x!=F) {
			FOR(y,N) if(y!=F && A[y]==B[x]) {
				C[y]=x;
				A[y]=-1;
				break;
			}
		}
		
		
		while(1) {
			int L,R;
			FOR(L,F) if(C[L]>F) break;
			for(R=F-1;R>=0;R--) if(C[R]<F) break;
			
			if(L>=R) break;
			goswap(L,R);
		}
		while(1) {
			int L,R;
			for(L=F+1;L<N;L++) if(C[L]>F) break;
			for(R=N-1;R>F;R--) if(C[R]<F) break;
			
			if(L>=R) break;
			goswap(L,R);
		}
		
		int num=0;
		FOR(i,F) if(C[i]>F) num++;
		if(num) {
			goswap(F-num,F+num);
		}
		FOR(i,F) if(C[i]!=i) {
			for(x=i+1;x<F;x++) if(C[x]==i) break;
			goswap(i,x);
		}
		
		for(i=F+1;i<N;i++) if(C[i]!=i) {
			for(x=i+1;x<N;x++) if(C[x]==i) break;
			goswap(i,x);
		}
		
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {10, 20, 30, 40, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, sort(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10, 20, 40, 30, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {-1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, sort(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {20, 10, 10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arr2[] = {0, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, sort(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 50, 40, 30, 20, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arr2[] = {1, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, sort(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {20, 10, 30, 50, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {0, 2, 3, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, sort(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FixedPointReversals ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

