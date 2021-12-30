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

class LogarithmCircuit {
	public:
	vector <int> construct(int N) {
		vector<vector<int>> R;
		
		int nex=N;
		int i,j;
		vector<int> C;
		FOR(i,20) {
			if(i<N) {
				C.push_back(i);
			}
			else {
				R.push_back({49,0,0});
				C.push_back(nex++);
			}
		}
		N=20;
		int step=1,d=0;
		for(int step=1;step<=N;step*=2) {
			d++;
			vector<int> C2;
			FOR(i,N) {
				if(i+step<N) {
					R.push_back({47,C[i],C[i+step]});
					C2.push_back(nex++);
				}
				else {
					C2.push_back(C[i]);
				}
			}
			C=C2;
		}
		
		vector<int> D;
		FOR(i,N-1) {
			R.push_back({49,C[i],C[i+1]});
			D.push_back(nex++);
		}
		D.push_back(C.back());
		
		
		vector<int> O;
		FOR(i,d) {
			queue<int> cand;
			FOR(j,D.size()) if(j&(1<<i)) cand.push(D[j]);
			while(cand.size()>=2) {
				int a=cand.front();
				cand.pop();
				int b=cand.front();
				cand.pop();
				R.push_back({47,a,b});
				cand.push(nex++);
			}
			O.push_back(cand.front());
		}
		
		vector<int> ret;
		ret.push_back(R.size());
		FORR(r,R) {
			ret.push_back(r[0]);
			ret.push_back(r[1]);
			ret.push_back(r[2]);
		}
		ret.push_back(O.size());
		FORR(o,O) ret.push_back(o);
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1, 50, 0, 0, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {4, 47, 0, 1, 48, 0, 1, 50, 0, 1, 48, 3, 4, 2, 1, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LogarithmCircuit ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

