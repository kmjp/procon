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
ll MD[305050];
int mi[305050];
ll D[21],S[21],M[21],I[21];

class Depot {
	public:
	vector<int> split_int(const string &str, char delim=' '){
		vector<int> res;
		size_t current = 0, found;
		while((found = str.find_first_of(delim, current)) != string::npos){
			string s = string(str, current, found - current);
			res.push_back(stoi(s));
			current = found + 1;
		}
		string s = string(str, current, str.size() - current);
		res.push_back(stoi(s));
		return res;
	}
	
	int countPositive(vector <string> arrivals, vector <string> queries) {
		N=arrivals.size();
		int i,j,x;
		
		ZERO(mi);
		FOR(i,305000) MD[i]=1LL<<60;
		MD[0]=0;
		mi[0]=-1;
		FOR(i,N) {
			auto v=split_int(arrivals[i]);
			D[i]=v[0];
			I[i]=v[1];
			M[i]=v[2];
			S[i]=v[3];
		}
		FOR(j,304000) {
			FOR(i,N) {
				ll nex=MD[j]+(i<=mi[j]);
				nex=max(nex,D[i]);
				nex=D[i]+(nex-D[i]+I[i]-1)/I[i]*I[i];
				if(nex>D[i]+(M[i]-1)*I[i] || j+S[i]>300000) continue;
				if(MD[j+S[i]]>nex) {
					MD[j+S[i]]=nex;
					mi[j+S[i]]=i;
				}
				if(MD[j+S[i]]==nex) mi[j+S[i]]=min(mi[j+S[i]],i);
			}
		}
		
		int ret=0;
		FORR(q,queries) {
			auto v=split_int(q);
			if(v.size()==2) {
				ret+=MD[v[1]]<=v[0];
			}
			else {
				ll d=v[0];
				ll s=v[1];
				ll A1=v[2];
				ll B1=v[3];
				ll A2=v[4];
				ll B2=v[5];
				int Q=v[6];
				FOR(i,Q) {
					ret+=MD[(s+i*A2-1)%B2+1]<=(d+i*A1-1)%B1+1;
				}
			}
		}
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 2 4 2", "4 3 2 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 1", "3 2", "3 4", "4 2", "5 3", "5 5", "7 6", "9 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, countPositive(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"3 2 4 2", "4 3 2 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 4 2 10 1 6 4", "5 3 8 9 8 9 3", "3 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, countPositive(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1 1 1 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1 1 5 1 5 100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; verify_case(2, Arg2, countPositive(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1 1 20000 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 10000 2 20000 10000 10000 10000", "2 10000 2 20000 10000 10000 10000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10001; verify_case(3, Arg2, countPositive(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"1 147 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"107 107 107 2 107 2 10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(4, Arg2, countPositive(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Depot ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

