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

class CardDrawGame {
	public:
	double winChance(int T, vector <int> C) {
		int N=C.size();
		int x,y,z,a,b,c;
		double ret=0;
		int S=0;
		FORR(c,C) S+=c;
		FOR(x,N) if(C[x]) {
			double p1=1.0*(C[x]--)/(S--);
			FOR(y,N) if(C[y]) {
				double p2=p1*(C[y]--)/(S--);
				FOR(z,N) if(C[z]) {
					double p3=p2*(C[z]--)/(S--);
					
					double ma=0;
					
					
					double PP[4][61]={};
					FOR(a,N) if(C[a]) {
						double q1=1.0*(C[a]--)/(S--);
						PP[1][a]+=q1;
						FOR(b,N) if(C[b]) {
							double q2=q1*(C[b]--)/(S--);
							PP[2][a+b]+=q2;
							FOR(c,N) if(C[c]) {
								double q3=q2*C[c]/S;
								PP[3][a+b+c]+=q3;
							}
							C[b]++,S++;
						}
						C[a]++,S++;
					}
					
					if(x+y+z==T) ma=1;
					if(T-x-y>=0) ma=max(ma,PP[1][T-x-y]);
					if(T-x-z>=0) ma=max(ma,PP[1][T-x-z]);
					if(T-z-y>=0) ma=max(ma,PP[1][T-z-y]);
					if(T-x>=0) ma=max(ma,PP[2][T-x]);
					if(T-y>=0) ma=max(ma,PP[2][T-y]);
					if(T-z>=0) ma=max(ma,PP[2][T-z]);
					ma=max(ma,PP[3][T]);
					//cout<<x<<y<<z<<" "<<p3<<" "<<ma<<endl;
					ret+=p3*ma;
					
					C[z]++,S++;
				}
				C[y]++,S++;
			}
			C[x]++,S++;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, winChance(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, winChance(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(2, Arg2, winChance(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arr1[] = {1, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.7000000000000001; verify_case(3, Arg2, winChance(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; int Arr1[] = {0,0,0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(4, Arg2, winChance(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 0; int Arr1[] = {3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.39999999999999997; verify_case(5, Arg2, winChance(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 5; int Arr1[] = {1,2,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.6333333333333331; verify_case(6, Arg2, winChance(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CardDrawGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

