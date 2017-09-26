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

string Y="Possible";
string N="Impossible";

class RememberWordsEasy {
	public:
	ll LV(ll S,ll D) {
		ll L=max(S-(D-1),0LL);
		return (S+L)*(S-L+1)/2;
	}
	ll RV(ll S,ll D) {
		ll R=S+(D-1);
		return (S+R)*(D)/2;
	}
	
	ll lowest(int D,int W) {
		ll v=(1LL<<30)-1;
		for(int i=29;i>=0;i--) if(RV(v-(1LL<<i),D)>=W) v-=1LL<<i;
		return v;
	}
	ll highest(int D,int W) {
		ll v=0;
		if(W==0) return 0;
		for(int i=29;i>=0;i--) if(LV(v+(1LL<<i),D)<=W) v+=1LL<<i;
		return v;
	}
	string isPossible(int d1, int d2, int w1, int w2) {
		ll L1=lowest(d1,w1);
		ll R1=highest(d1,w1);
		ll L2=lowest(d2,w2);
		ll R2=highest(d2,w2);
		cout<<L1<<" "<<R1<<endl;
		cout<<L2<<" "<<R2<<endl;
		
		if(L1>R1 || L2>R2) return N;
		if(R1+1==L2) return Y;
		if(R2+1==L1) return Y;
		if(max(L1,L2)<=min(R1,R2)) return Y;
		return N;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 7; int Arg3 = 18; string Arg4 = "Possible"; verify_case(0, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 3; int Arg3 = 5; string Arg4 = "Impossible"; verify_case(1, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 300; int Arg3 = 500; string Arg4 = "Possible"; verify_case(2, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 1; int Arg2 = 0; int Arg3 = 2; string Arg4 = "Impossible"; verify_case(3, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 1000000; int Arg2 = 1000000; int Arg3 = 1000000; string Arg4 = "Possible"; verify_case(4, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RememberWordsEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

