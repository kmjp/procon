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

class ProductThreshold {
	public:
	ll L;
	vector<ll> A,B;
	
	ll hoge() {
		vector<int> C[3];
		int i;
		int N=B.size();
		C[0].push_back(0);
		C[1].push_back(0);
		C[2].push_back(0);
		int cur=0;
		FOR(i,N) {
			if(B[i]<0) cur^=1;
			C[2].push_back(cur);
			C[0].push_back(C[0].back()+(cur==0));
			C[1].push_back(C[1].back()+(cur==1));
		}
		vector<int> nex(N+1);
		nex[N]=N;
		int ne=N;
		for(i=N-1;i>=0;i--) {
			nex[i]=ne;
			if(abs(B[i])>1) ne=i;
		}
		
		ll ret=0;
		FOR(i,N) {
			ll cur=B[i];
			int R=i;
			while(abs(cur)<=L && R<N) {
				R=nex[R];
				if(R==N) break;
				cur*=B[R];
			}
			ret+=R-i;
			int cb=C[2][i]^1;
			ret+=C[cb].back()-C[cb][R];
		}
		return ret;
		
		
	}
	
	long long subarrayCount(int N, int limit, vector <int> Aprefix, int spread, int offset) {
		L=limit;
		A.clear();
		FORR(a,Aprefix) A.push_back(a);
		ll seed = abs(A.back());
		int i;
		for(i=Aprefix.size();i<N;i++) {
			seed = (seed*1103515245LL + 12345) % (1LL<<31);
			A.push_back(seed%spread+offset);
		}
		
		ll ret=0;
		int pre=-1;
		B.clear();
		FOR(i,N) {
			if(A[i]==0) {
				ret+=1LL*(i-pre)*(N-i);
				ret += hoge();
				B.clear();
				pre=i;
			}
			else {
				B.push_back(A[i]);
			}
		}
		ret+=hoge();
		
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {1,2,3,-4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 1; long long Arg5 = 13LL; verify_case(0, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 8; int Arr2[] = {2,2,2,2,2,2,2,2,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 47; long long Arg5 = 27LL; verify_case(1, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 999888777; int Arr2[] = {47}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7654321; int Arg4 = 1; long long Arg5 = 21LL; verify_case(2, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 8; int Arr2[] = {3,0,3,0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 47; int Arg4 = 47; long long Arg5 = 15LL; verify_case(3, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 1; int Arr2[] = {-1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 2; long long Arg5 = 1000LL; verify_case(4, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 100; int Arg1 = 47; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 1; long long Arg5 = 5050LL; verify_case(5, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ProductThreshold ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

