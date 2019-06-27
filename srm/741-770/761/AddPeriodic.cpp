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

const int L=300;

class AddPeriodic {
	public:
	pair<ll,string> conv(string A) {
		ll v=0;
		int i,j;
		string B;
		FOR(i,A.size()) {
			if(A[i]=='.') break;
			v=v*10+A[i]-'0';
		}
		
		for(j=i+1;j<A.size();j++) {
			if(A[j]!='(') {
				B+=A[j];
			}
			else {
				int x=j+1;
				int y=A.size()-1;
				FOR(i,L+200) {
					B.push_back(A[x+i%(y-x)]);
				}
				break;
				
			}
			
		}
		B.resize(L+200);
		return {v,B};
		
	}
	
	string add(string A, string B) {
		auto a=conv(A);
		auto b=conv(B);
		string S;
		int i,c=0;
		for(i=L+199;i>=0;i--) {
			int x=a.second[i]-'0'+b.second[i]-'0'+c;
			S.push_back('0'+x%10);
			c=x/10;
		}
		reverse(ALL(S));
		ll v=a.first+b.first+c;
		
		string R(500,'1');
		int s,l,x;
		FOR(s,L) {
			for(l=1;s+l<=L;l++) {
				int ok=1;
				for(x=s;x<L;x+=l) {
					int le=min(l,L-x);
					if(S.substr(s,le)!=S.substr(x,le)) {
						ok=0;
						break;
					}
				}
				if(ok==0) continue;
				string P=S.substr(0,s);
				string Q=S.substr(s,l);
				if(Q=="9") {
					Q="0";
					int c=1;
					for(i=(int)P.size()-1;i>=0;i--) {
						if(P[i]=='9') {
							P[i]='0';
							c=1;
						}
						else {
							P[i]++;
							c=0;
							break;
						}
					}
					v+=c;
				}
				
				string ret=to_string(v)+"."+P+"("+Q+")";
				if(ret.size()<R.size()) R=ret;
				break;
			}
		}
			
		
		
		
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0.33(333)"; string Arg1 = "0.(66)"; string Arg2 = "1.(0)"; verify_case(0, Arg2, add(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "2.41(5)"; string Arg1 = "5.36(22)"; string Arg2 = "7.(7)"; verify_case(1, Arg2, add(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "685.4(757)"; string Arg1 = "45.356(43)"; string Arg2 = "730.832(210119)"; verify_case(2, Arg2, add(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "0.(101)"; string Arg1 = "0.(23)"; string Arg2 = "0.(333424)"; verify_case(3, Arg2, add(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "0.0(999999)"; string Arg1 = "1.5(00000)"; string Arg2 = "1.6(0)"; verify_case(4, Arg2, add(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AddPeriodic ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

