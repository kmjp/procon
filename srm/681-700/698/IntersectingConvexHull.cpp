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



class IntersectingConvexHull {
	public:
	
	int count(vector <int> x, vector <int> y) {
		ll mo=1000000007;
		ll C[110][110];
		ll p2[110];
		int N=x.size();
		int i,j,k;
		
		FOR(i,104) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
		
		p2[0]=1;
		FOR(i,104) p2[i+1]=p2[i]*2%mo;
		
		ll ret=0;
		for(i=3;i<=N;i++) for(j=3;i+j<=N;j++) ret = (ret + C[N][i]*C[N-i][j])%mo;
		
		FOR(i,N) FOR(j,N) if(i!=j) {
			int num[2]={};
			FOR(k,N) if(i!=k && j!=k) num[(1LL*(x[i]-x[j])*(y[k]-y[j])-1LL*(y[i]-y[j])*(x[k]-x[j]))>0]++;
			if(num[0]<2 || num[1]<2) continue;
			
			ll a=p2[num[0]]-1-num[0];
			ll b=p2[num[1]]-1-num[1];
			
			ret = (ret-a*b%mo+mo)%mo;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0,-1,-1,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,1,-1,-2,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {444, -646, 367, 302, -506, 810}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-530, 660, 872, -78, -621, 77}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-737, -245, -51, 943, -7, 1000, -976, -723}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-355, 898, -372, -585, -98, -53, 490, -954}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 900; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-928, 852, 840, 813, -564, -594, -667, 838, -74, -675, -530, -476, -154, 702, 817, 969, 845, 592, 867, -330}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-898, 682, 604, 22, -452, 901, 464, -624, -272, -792, -906, 36, 249, -287, 871, 877, 446, 910, 943, 427}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 296398747; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  IntersectingConvexHull ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
