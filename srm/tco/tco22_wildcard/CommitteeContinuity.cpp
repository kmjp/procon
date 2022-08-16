#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int YM[55];
ll from[1<<10][55];
ll to[1<<10][55];
const ll mo=1000000007;

ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

class CommitteeContinuity {
	public:
	int count(int M, int Y, vector <int> year, vector <int> member) {
		map<int,int> A;
		ZERO(from);
		ZERO(YM);
		int nex=0;
		int i;
		FOR(i,year.size()) {
			int m=member[i];
			if(A.count(m)==0) {
				A[m]=nex++;
			}
			YM[year[i]]|=1<<A[m];
		}
		int lef=M-nex;
		int mask;
		FOR(mask,1<<nex) if((mask&YM[0])==YM[0]) {
			FOR(i,lef+1) from[mask][i]=comb(lef,i);
		}
		from[0][0]=0;
		int yy;
		for(yy=1;yy<Y;yy++) {
			ZERO(to);
			ll sum=0;
			FOR(mask,1<<nex) FOR(i,lef+1) sum+=from[mask][i];
			sum%=mo;
			FOR(mask,1<<nex) FOR(i,lef+1) to[mask][i]=sum*comb(lef,i)%mo;
			
			int x,y;
			FOR(x,lef+1) {
				ll A[1<<10]={};
				FOR(mask,1<<nex) A[mask]=from[mask][x];
				FOR(y,nex) FOR(mask,1<<nex) if(mask&(1<<y)) (A[mask]+=A[mask^(1<<y)])%=mo;
				for(y=0;x+y<=lef;y++) {
					ll p=comb(lef-x,y);
					FOR(mask,1<<nex) (to[mask][y]+=mo-p*A[(1<<nex)-1-mask]%mo)%=mo;
				}
			}
			
			
			FOR(mask,1<<nex) if((mask&YM[yy])!=YM[yy]) {
				FOR(i,lef+1) to[mask][i]=0;
			}
			
			swap(from,to);
		}
		ll sum=0;
		FOR(mask,1<<nex) FOR(i,lef+1) sum+=from[mask][i];
		return sum%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {0, 1, 2, 3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 0, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1024; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 17; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 9; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 40; int Arg1 = 1; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 511620082; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 5; int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 111156; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CommitteeContinuity ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

