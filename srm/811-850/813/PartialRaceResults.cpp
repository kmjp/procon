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

map<char,int> M;
vector<int> E[66];
int vis[66];
int in[66];
class PartialRaceResults {
	public:
	string reconstruct(vector <string> memories) {
		string S="";
		int i;
		FOR(i,10) S+='0'+i;
		FOR(i,26) S+='a'+i;
		FOR(i,26) S+='A'+i;
		FOR(i,S.size()) {
			M[S[i]]=i;
			E[i].clear();
			vis[i]=1;
		}
		ZERO(in);
		FORR(a,memories) {
			E[M[a[2]]].push_back(M[a[0]]);
			E[M[a[0]]].push_back(M[a[3]]);
			vis[M[a[0]]]=0;
			vis[M[a[2]]]=0;
			vis[M[a[3]]]=0;
			in[M[a[0]]]++;
			in[M[a[3]]]++;
		}
		int ma=0;
		queue<int> Q;
		string ret;
		FOR(i,S.size()) {
			if(vis[i]==0) ma++;
			if(vis[i]==0&&in[i]==0) Q.push(i);
		}
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			ret+=S[cur];
			FORR(e,E[cur]) {
				in[e]--;
				if(in[e]==0) Q.push(e);
			}
		}
		
		cout<<ret<<endl;
		if(ret.size()!=ma) return "";
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"B:AC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABC"; verify_case(0, Arg1, reconstruct(Arg0)); }
	void test_case_1() { string Arr0[] = {"B:AD", "7:BD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AB7D"; verify_case(1, Arg1, reconstruct(Arg0)); }
	void test_case_2() { string Arr0[] = {"A:BC", "B:AC", "C:AB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(2, Arg1, reconstruct(Arg0)); }
	void test_case_3() { string Arr0[] = {"A:bc", "A:cb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(3, Arg1, reconstruct(Arg0)); }
	void test_case_4() { string Arr0[] = {"0:39", "2:05", "1:37", "2:18", "5:78", "6:29", "5:46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "4310725869"; verify_case(4, Arg1, reconstruct(Arg0)); }
	void test_case_5() { string Arr0[] = {"A:AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(5, Arg1, reconstruct(Arg0)); }
	void test_case_6() { string Arr0[] = {"a:bc", "0:12", "X:YZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1YbX0ac2Z"; verify_case(6, Arg1, reconstruct(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PartialRaceResults ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

