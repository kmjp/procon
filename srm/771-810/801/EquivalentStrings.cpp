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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class EquivalentStrings {
	public:
	string trans(string S) {
		vector<int> pep[2525];
		int did[2525]={};
		int C[10];
		int fin[10];
		int i,j;
		queue<int> cand[10];
		FOR(i,10) {
			C[i]=fin[i]=-1;
		}
		FOR(i,S.size()) {
			cand[S[i]-'0'].push(i);
			pep[i].push_back(C[S[i]-'0']);
			if(S[i]!='9') pep[i].push_back(C[S[i]-'0'+1]);
			if(S[i]!='0') pep[i].push_back(C[S[i]-'0'-1]);
			C[S[i]-'0']=i;
		}
		
		string T;
		
		FOR(i,S.size()) {
			int j;
			FOR(j,10) if(cand[j].size()) {
				int x=cand[j].front();
				int ok=1;
				FORR(p,pep[x]) if(p>=0 &&did[p]==0) ok=0;
				if(ok) {
					T.push_back('0'+j);
					did[x]=1;
					cand[j].pop();
					break;
				}
			}
		}
		
		return T;
	}
	
	int count(vector <string> seeds) {
		set<string> V;
		FORR(v,seeds) {
			int N=v.size(),j;
			FOR(j,N) {
				V.insert(trans(v));
				v=v.substr(1,N-1)+v.substr(0,1);
			}
		}
		
		return V.size();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"017040"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"474", "474", "744", "474"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"0123456789", "02468"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(2, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EquivalentStrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

