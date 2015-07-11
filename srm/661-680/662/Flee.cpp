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

class Flee {
	public:
	
	bool inside(vector<int> x,vector<int> y) {
		ll a=x[0]*y[1]-x[1]*y[0];
		ll b=x[1]*y[2]-x[2]*y[1];
		ll c=x[2]*y[0]-x[0]*y[2];
		return (a*b>=0 && b*c>=0 && c*a>=0);
	}
	
	double maximalSafetyLevel(vector <int> x, vector <int> y) {
		double ret=1e10;
		int i;
		set<pair<int,int> > S;
		FOR(i,x.size()) S.insert({x[i],y[i]});
		x.clear();
		y.clear();
		FORR(r,S) x.push_back(r.first),y.push_back(r.second);
		FOR(i,x.size()) ret=min(ret,sqrt(x[i]*x[i]+y[i]*y[i]));
		
		if(x.size()==3 && inside(x,y)) {
			double ma=0;
			FOR(i,3) {
				double dx=(x[i]-x[(i+1)%3])*0.5;
				double dy=(y[i]-y[(i+1)%3])*0.5;
				ma=max(ma,sqrt(dx*dx+dy*dy));
			}
			ret=min(ret,ma);
			
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,-7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,-5,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 5.0; verify_case(0, Arg2, maximalSafetyLevel(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-5,-5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 5.0990195135927845; verify_case(1, Arg2, maximalSafetyLevel(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,-8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,-5,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 5.0990195135927845; verify_case(2, Arg2, maximalSafetyLevel(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {232,312,-432}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {498,-374,24}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 432.6661530556787; verify_case(3, Arg2, maximalSafetyLevel(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(4, Arg2, maximalSafetyLevel(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Flee ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
