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

class PolygonRotation {
	public:
	double LX[202];
	double RX[202];
	
	double integral(double a,double b,double t) {
		double pi=atan(1)*4;
		
		return pi*(a*a*t*t*t/3.0+a*b*t*t+b*b*t);
	}
	
	double getVolume(vector <int> x, vector <int> y) {
		int N=x.size();
		int yma,ymi;
		int i;
		FOR(i,N) y[i]+=100;
		FOR(i,N) {
			if(i==0) yma=y[i];
			else if(x[i]>0) {
				if(y[i]==y[i-1]) RX[y[i]]=x[i];
				else {
					for(int ty=y[i-1]-1;ty>=y[i];ty--) RX[ty] = (x[i-1]*(ty-y[i])+x[i]*(y[i-1]-ty))*1.0/(y[i-1]-y[i]);
				}
			}
			else if(x[i]==0) {
				ymi=y[i];
				if(y[i-1]!=y[i]) {
					for(int ty=y[i-1]-1;ty>=y[i];ty--) RX[ty] = (x[i-1]*(ty-y[i])+x[i]*(y[i-1]-ty))*1.0/(y[i-1]-y[i]);
				}
			}
			else if(x[i]<0) {
				if(y[i]==y[i-1]) LX[y[i]]=-x[i];
				else {
					for(int ty=y[i-1]+1;ty<=y[i];ty++) LX[ty] = -(x[i-1]*(y[i]-ty)+x[i]*(ty-y[i-1]))*1.0/(y[i]-y[i-1]);
				}
			}
		}
		if(y[0]!=y[N-1]) {
			for(int ty=y[N-1]+1;ty<=y[0];ty++) LX[ty] = -(x[N-1]*(y[0]-ty)+x[0]*(ty-y[N-1]))*1.0/(y[0]-y[N-1]);
		}
		
		double ret=0;
		for(int y=ymi;y<yma;y++) {
			if(LX[y]>=RX[y] && LX[y+1]>=RX[y+1]) {
				ret += integral(LX[y+1]-LX[y],LX[y],1);
			}
			else if(RX[y]>=LX[y] && RX[y+1]>=LX[y+1]) {
				ret += integral(RX[y+1]-RX[y],RX[y],1);
			}
			else if(LX[y]>RX[y] && LX[y+1]<RX[y+1]) {
				double a=LX[y]-RX[y];
				double b=RX[y+1]-LX[y+1];
				double p=a/(a+b);
				ret += integral(LX[y+1]-LX[y],LX[y],p);
				ret += integral(RX[y]-RX[y+1],RX[y+1],1-p);
			}
			else if(LX[y]<RX[y] && LX[y+1]>RX[y+1]) {
				double a=RX[y]-LX[y];
				double b=LX[y+1]-RX[y+1];
				double p=a/(a+b);
				ret += integral(RX[y+1]-RX[y],RX[y],p);
				ret += integral(LX[y]-LX[y+1],LX[y+1],1-p);
			}
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.141592653589793; verify_case(0, Arg2, getVolume(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 1, 0, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0943951023931953; verify_case(1, Arg2, getVolume(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 3, 0, -2, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, -3, -1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 49.91641660703782; verify_case(2, Arg2, getVolume(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 3, 3, 0, -1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, -2, -2, -1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 113.09733552923255; verify_case(3, Arg2, getVolume(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PolygonRotation ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

