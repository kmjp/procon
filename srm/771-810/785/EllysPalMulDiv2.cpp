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

class EllysPalMulDiv2 {
	public:
	pair<int,int> rev(int a) {
		int v=0;
		int d=0;
		while(a) {
			d++;
			v=v*10+a%10;
			a/=10;
		}
		return {v,d};
	}
	
	int getMin(int X) {
		if(X%10==0) return -1;
		
		ll p10[100]={};
		p10[0]=1;
		int i;
		FOR(i,10) p10[i+1]=p10[i]*10;
		
		ll mi=1LL<<60;
		
		for(i=1;i<=10000000;i++) {
			ll a=i;
			auto v=rev(i);
			ll b=v.first;
			int d=v.second;
			ll v1=a*p10[d]+b;
			ll v2=a/10*p10[d]+b;
			//cout<<i<<" "<<v1<<" "<<v2<<endl;
			if(v1%X==0) mi=min(mi,v1/X);
			if(v2%X==0) mi=min(mi,v2/X);
			
		}
		if(mi>1000) return -1;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 42; int Arg1 = 6; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { int Arg0 = 121; int Arg1 = 1; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { int Arg0 = 1337; int Arg1 = 143; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { int Arg0 = 13; int Arg1 = 38; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = -1; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { int Arg0 = 39325; int Arg1 = -1; verify_case(5, Arg1, getMin(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysPalMulDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

