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


ll C[303030];
ll P[303030];
int nex[303030];
int L[1303030],R[1303030];

ll powers[1303030];
set<pair<int,int>> cand;
ll state;

class ItsWhomYouKnow {
	public:
	
	void add(int x) {
		int c=C[x];
		cand.erase({-powers[c],c});
		if(L[c]==-1) {
			L[c]=R[c]=x;
			nex[x]=-1;
		}
		else {
			nex[R[c]]=x;
			nex[x]=-1;
			R[c]=x;
		}
		powers[c]=max(powers[c],P[x]);
		cand.insert({-powers[c],c});
	}
	void del(int c) {
		L[c]=nex[L[c]];
		if(L[c]==-1) cand.erase({-powers[c],c});
	}
	long long simulate(int N, int C_, int P_, vector <int> initialClans, vector <int> initialPowers, int seed) {
		int i;
		cand.clear();
		FOR(i,C_) {
			L[i]=R[i]=powers[i]=-1;
		}
		FOR(i,initialClans.size()) {
			C[i]=initialClans[i];
			P[i]=initialPowers[i];
			add(i);
		}
		int nex=initialClans.size();
		state=seed;
		ll ret=0;
		int j;
		FOR(i,N) {
			FOR(j,2) {
				state = (state * 1103515245 + 12345)%(1LL<<31);
				C[nex]=state/10%C_;
				state = (state * 1103515245 + 12345)%(1LL<<31);
				P[nex]=state%P_;
				add(nex);
				nex++;
			}
			int c=cand.begin()->second;
			ret+=1LL*(i+1)*L[c];
			state=(state+L[c])%(1LL<<31);
			del(c);
		}
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 1000; int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 47; long long Arg6 = 51LL; verify_case(0, Arg6, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 1000; int Arr3[] = {4, 7, 1, 2, 4, 4, 0, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {13, 2, 55, 17, 600, 0, 101, 100}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 47; long long Arg6 = 44LL; verify_case(1, Arg6, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1000; int Arg2 = 1000; int Arr3[] = {123, 789, 456}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {999, 999, 999}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 47; long long Arg6 = 7LL; verify_case(2, Arg6, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ItsWhomYouKnow ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

