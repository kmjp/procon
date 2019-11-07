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

ll A[101010];
ll B[101010];
ll C[101010];
ll mo=1000000007;

class DeleteArrays {
	public:
	vector<long long> doDelete(int a, int b, int c, long long x, long long y, long long z) {
		int i,j;
		A[0]=33,A[1]=42;
		B[0]=13;
		C[0]=7,C[1]=2;
		for(i=2;i<a;i++) A[i]=(5*A[i-1]+7*A[i-2])%mo+1;
		for(i=1;i<b;i++) B[i]=(11*B[i-1])%mo+1;
		for(i=2;i<c;i++) C[i]=(5*C[i-1]+7*C[i-2])%mo+1;
		ll S=0;
		sort(A,A+a);
		sort(B,B+b);
		sort(C,C+c);
		FOR(i,a) S+=A[i];
		FOR(i,b) S+=B[i];
		FOR(i,c) S+=C[i];
		
		if(a>=b+c) {
			ll lef=0;
			FOR(i,a-b-c) lef+=A[i];
			return {lef,x*b+z*c+S-lef};
		}
		if(b>=a+c) {
			ll lef=0;
			FOR(i,b-a-c) lef+=B[i];
			return {lef,x*a+y*c+S-lef};
		}
		if(c>=a+b) {
			ll lef=0;
			FOR(i,c-a-b) lef+=C[i];
			return {lef,y*b+z*a+S-lef};
		}
		
		vector<ll> mi={1LL<<60,1LL<<60};
		FOR(i,4) {
			ll co=0;
			if(i==1) a--, co=A[0];
			if(i==2) b--, co=B[0];
			if(i==3) c--, co=C[0];
			
			if((a+b+c)%2==0) {
				int pqr=(a+b+c)/2;
				int p=pqr-c;
				int q=pqr-a;
				int r=pqr-b;
				vector<ll> tmp={co,p*x+q*y+r*z+S-co};
				mi=min(mi,tmp);
				
			}
			
			if(i==1) a++;
			if(i==2) b++;
			if(i==3) c++;
		}
		
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; long long Arg3 = 2LL; long long Arg4 = 3LL; long long Arg5 = 4LL; long Arr6[] = {0, 250 }; vector<long long> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, doDelete(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; long long Arg3 = 3LL; long long Arg4 = 2LL; long long Arg5 = 1LL; long Arr6[] = {2, 688 }; vector<long long> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, doDelete(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 4; long long Arg3 = 5LL; long long Arg4 = 6LL; long long Arg5 = 7LL; long Arr6[] = {0, 22620 }; vector<long long> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, doDelete(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 100000; int Arg1 = 5; int Arg2 = 8; long long Arg3 = 424242LL; long long Arg4 = 474747LL; long long Arg5 = 123456789LL; long Arr6[] = {50097960828195, 13989929548 }; vector<long long> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(3, Arg6, doDelete(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DeleteArrays ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

