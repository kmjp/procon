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

double memo[1010][1010];


class Literature {
	public:
	int N;
	double hoge(int A,int B) {
		assert(A && B);
		if(memo[A][B]>=0) return memo[A][B];
		double ret=0;
		double add=3*(2*N)*(2*N)*1.0/(2*N*(A+B)-A*B)-3;
		
		double AB=1.0*A*B/(2*N*(A+B)-A*B);
		double Ab=1.0*A*(2*N-B)/(2*N*(A+B)-A*B);
		double aB=1.0*(2*N-A)*B/(2*N*(A+B)-A*B);
		
		// oo
		if(A==1 && B==1) {
			ret+=(AB+Ab)*(add+1);
			ret+=aB*(add+2);
		}
		else if(A==1) {
			ret+=(AB+Ab)*(add+1);
			ret+=aB*(add+3+hoge(A,B-1));
		}
		else if(B==1) {
			ret+=(AB+aB)*(add+2);
			ret+=Ab*(add+3+hoge(A-1,B));
		}
		else {
			ret+=AB*(add+3+hoge(A-1,B-1));
			ret+=Ab*(add+3+hoge(A-1,B));
			ret+=aB*(add+3+hoge(A,B-1));
		}
		
		
		return memo[A][B]=ret;
	}
	
	double expectation(int n, vector <int> Teja, vector <int> history) {
		int did[3030]={};
		N=n;
		int lef[2]={N,N};
		FORR(a,Teja) did[a]=1;
		int i;
		FOR(i,history.size()) {
			if(did[history[i]]) continue;
			if(i%3==0) continue;
			did[history[i]]=1;
			if(i%3==1) lef[1]--;
			if(i%3==2) lef[0]--;
			if(lef[0]==0 || lef[1]==0) return i+1;
		}
		int cur=history.size();
		
		int x,y;
		FOR(x,1010) FOR(y,1010) memo[x][y]=-1;
		
		
		
		if(cur%3==0) cur++;
		
		if(cur%3==1) return cur+hoge(lef[1],lef[0]);
		else return cur+lef[0]*1.0/(2*N)*(lef[0]==1?1:(2+hoge(lef[1],lef[0]-1)))+(2*N-lef[0])*1.0/(2*N)*(2+hoge(lef[1],lef[0]));
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 3.333333333333333; verify_case(0, Arg3, expectation(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,1,6,6,2,5,2,4,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 6.0; verify_case(1, Arg3, expectation(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {5,29,12,16,25,17,18,30,27,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,6,5,23,22,29,20,8,12,3,13,16,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 133.0880654696573; verify_case(2, Arg3, expectation(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Literature ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

