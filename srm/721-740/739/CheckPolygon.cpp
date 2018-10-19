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

class CheckPolygon {
	public:
	
	int ispar(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3) {
		x1-=x2;
		x3-=x2;
		y1-=y2;
		y3-=y2;
		return x1*y3-x3*y1==0;
		
	}
	int cross(ll x11,ll y11,ll x12,ll y12,ll x21,ll y21,ll x22,ll y22) {
		ll a=(x21-x11)*(y12-y11)-(y21-y11)*(x12-x11);
		ll b=(x22-x11)*(y12-y11)-(y22-y11)*(x12-x11);
		if(a && b && ((a<0)==(b<0))) return 0;
		a=(x11-x21)*(y22-y21)-(y11-y21)*(x22-x21);
		b=(x12-x21)*(y22-y21)-(y12-y21)*(x22-x21);
		
		if(a && b && ((a<0)==(b<0))) return 0;
		return 1;
	}
	int ison(ll x1,ll y1,ll x2,ll y2) {
		return (x1*x2+y1*y2<=0) && (x1*y2-x2*y1==0);
	}
	
	string check(vector <int> X, vector <int> Y) {
		int N=X.size();
		X.push_back(X[0]);
		Y.push_back(Y[0]);
		int i,j;
		FOR(i,N) if(X[i]==X[i+1] && Y[i]==Y[i+1]) return "Not simple";
		FOR(i,N-1) if(ispar(X[i],Y[i],X[i+1],Y[i+1],X[i+2],Y[i+2])) return "Not simple";
		
		FOR(i,N) FOR(j,N) if(abs(i-j)>1 && abs(i-j)<N-1) {
			
			if(ispar(X[i],Y[i],X[i+1],Y[i+1],X[j+1]-X[j]+X[i+1],Y[j+1]-Y[j]+Y[i+1])) {
				if(ison(X[i]-X[j],  Y[i]-Y[j],  X[i+1]-X[j],  Y[i+1]-Y[j])) return "Not simple";
				if(ison(X[i]-X[j+1],Y[i]-Y[j+1],X[i+1]-X[j+1],Y[i+1]-Y[j+1])) return "Not simple";
				if(ison(X[j]-X[i],  Y[j]-Y[i],  X[j+1]-X[i],  Y[j+1]-Y[i])) return "Not simple";
				if(ison(X[j]-X[i+1],Y[j]-Y[i+1],X[j+1]-X[i+1],Y[j+1]-Y[i+1])) return "Not simple";
			}
			else {
				if(cross(X[i],Y[i],X[i+1],Y[i+1],X[j],Y[j],X[j+1],Y[j+1])) return "Not simple";
			}
		}
		
		ll a=0;
		FOR(i,N) a+=1LL*X[i+1]*Y[i]-1LL*Y[i+1]*X[i];
		a=abs(a);
		
		char buf[50];
		sprintf(buf, "%lld.%d",a/2,(a%2)?5:0);
		return string(buf);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "0.5"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,1,2,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,0,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not simple"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,1,2,1,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1,2,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "2.0"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1000000000, -1000000000, -999999999, -999999999, -999999998, -999999998, -999999997, -999999997, -999999996, -999999996, -999999995, -999999995, -999999994, -999999994, -999999993, -999999993, -999999992, -999999992, -999999991, -999999991, -999999990, -999999990}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1000000000, -999999998, -999999998, -999999999, -999999999, -999999998, -999999998, -999999999, -999999999, -999999998, -999999998, -999999999, -999999999, -999999998, -999999998, -999999999, -999999999, -999999998, -999999998, -999999999, -999999999, -1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "15.0"; verify_case(2, Arg2, check(Arg0, Arg1)); }



// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CheckPolygon ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

