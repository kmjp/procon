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

int N;
double sum[1<<20];
double prob[1<<20];
double p[20];
double ps[1<<20];

class RareItems {
	public:
	double expectedPurchases(vector <int> frequency) {
		int N=frequency.size();
		int i,S=0,mask;
		FOR(i,N) p[i]=frequency[i], S+=p[i];
		FOR(i,N) p[i]/=S;
		FOR(mask,1<<N) {
			ps[mask]=0;
			prob[mask]=sum[mask]=0;
			FOR(i,N) if(mask&(1<<i)) ps[mask]+=p[i];
		}
		prob[0]=1;
		FOR(mask,(1<<N)-1) {
			double getnew=1.0/(1-ps[mask]);
			double nex=sum[mask]/prob[mask]+getnew;
			FOR(i,N) if((mask&(1<<i))==0) {
				double cp=prob[mask]*(p[i]/(1-ps[mask]));
				sum[mask^(1<<i)] += cp*nex;
				prob[mask^(1<<i)] += cp;
			}
			
		}
		return sum[(1<<N)-1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, expectedPurchases(Arg0)); }
	void test_case_1() { int Arr0[] = {2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(1, Arg1, expectedPurchases(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 153.00019801980199; verify_case(2, Arg1, expectedPurchases(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RareItems ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

