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

class MakePolygon {
	public:
	int area(vector<pair<int,int>> P) {
		int ret=0;
		int i;
		P.push_back(P[0]);
		FOR(i,P.size()-1) {
			ret+=P[i].first*P[i+1].second-P[i+1].first*P[i].second;
		}
		ret=abs(ret);
		return ret;
		
	}
	int pat[51][51];
	vector <int> make(int N) {
		vector<pair<int,int>> P;
		int x,y;
		cin>>N;
		int ON=N;
		
		if(N<=50) {
			deque<pair<int,int>> D;
			for(int y=1;D.size()<min(50,N);y++) {
				D.push_front({2-y%2,y});
				if(D.size()<N) D.push_back({3-y%2,y});
			}
			FORR(d,D) P.push_back(d);
		}
		else {
			N-=50;
			P.push_back({3,1});
			for(y=2;y<=22;y+=2) {
				P.push_back({2,y});
				vector<pair<int,int>> A,B;
				deque<pair<int,int>> D;
				for(x=3;x<=25;x++) {
					if(x==3) {
						if(N) A.push_back({x,y}), N--;
					}
					else {
						if(N) A.push_back({x,y+(1-x%2)}), N--;
						if(N) B.push_back({x,y+1+(1-x%2)}), N--;
					}
				}
				FORR(a,A) P.push_back(a);
				reverse(ALL(B));
				FORR(b,B) P.push_back(b);
				while(D.size()) P.push_back(D.front()), D.pop_front();
				P.push_back({3,y+1});
			}
			P.push_back({2,24});
			P.push_back({3,25});
			for(y=25;y>=1;y--) P.push_back({1+y%2,y});
			
		}
		
		FORR(p,P) cout<<p.first<<" "<<p.second<<endl;
		cout<<area(P)<<endl;
		assert(area(P)+2==ON);
		vector<int> Q;
		FORR(p,P) Q.push_back(p.first*100+p.second);
		
		return Q;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {101, 201, 102 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, make(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {101, 201, 202, 102 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, make(Arg0)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {101, 201, 303, 202, 102 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, make(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MakePolygon ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

