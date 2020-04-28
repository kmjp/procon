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

map<pair<int,int>,int> mask;
map<pair<int,int>,int> did;
vector<pair<int,int>> P;
vector<ll> cand;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


class PolylineAreas {
	public:
	string S,C;
	int step;
	
	string inst(string& S) {
		string cmd;
		if(S.back()=='[') {
			S.pop_back();
			cmd=program(S);
			assert(S.back()==']');
			S.pop_back();
		}
		else {
			cmd=S.substr(S.size()-1);
			S.pop_back();
		}
		return cmd;
	}
	string program(string& S) {
		if(S.empty()) return "";
		if(S.back()==']') return "";
		string cmd;
		if(S.back()>='0' && S.back()<='9') {
			int num=0;
			while(S.back()>='0' && S.back()<='9') {
				num=num*10+(S.back()-'0');
				S.pop_back();
			}
			string s=inst(S);
			if(s.size()) {
				while(num--) cmd+=s;
			}
		}
		else {
			cmd=inst(S);
		}
		
		return cmd+program(S);
	}
	
	vector<long long> findAreas(string polyline) {
		S=polyline;
		reverse(ALL(S));
		C=program(S);
		
		int X=0,Y=0;
		int d=0;
		int i,j;
		mask.clear();
		FORR(c,C) {
			if(c=='L') d++;
			if(c=='R') d+=3;
			d%=4;
			if(c=='F') {
				mask[{X,Y}] |= 1<<(d%4);
				did[{X,Y}]=0;
				X+=dx[d%4];
				Y+=dy[d%4];
				mask[{X,Y}] |= 1<<((d+2)%4);
				did[{X,Y}]=0;
			}
		}
		
		cand.clear();
		FORR(m,mask) {
			FOR(i,4) if((m.second&(1<<i)) && ((did[m.first] & (1<<i))==0)) {
				step++;
				P.clear();
				int X=m.first.first,Y=m.first.second;
				int dir=i+1;
				while(1) {
					P.push_back({X,Y});
					dir+=3;
					dir%=4;
					while((mask[{X,Y}] & (1<<dir))==0) dir=(dir+1)%4;
					if(did[{X,Y}] & (1<<dir)) break;
					did[{X,Y}] |= 1<<dir;
					int nx=X+dx[dir];
					int ny=Y+dy[dir];
					X=nx;
					Y=ny;
				}
				
				ll area=0;
				FOR(j,(int)P.size()-1) area += 1LL*P[j].first*P[j+1].second-1LL*P[j].second*P[j+1].first;
				if(area) cand.push_back(abs(area)/2);
			}
		}
		
		sort(ALL(cand));
		if(cand.size()) cand.pop_back();
		if(cand.size()>200) {
			vector<ll> ret;
			FOR(i,100) ret.push_back(cand[i]), ret.push_back(cand[cand.size()-1-i]);
			sort(ALL(ret));
			cand=ret;
		}
		
		return cand;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "FRFLF"; long Arr1[] = { }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findAreas(Arg0)); }
	void test_case_1() { string Arg0 = "4[100FR]"; long Arr1[] = {10000 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findAreas(Arg0)); }
	void test_case_2() { string Arg0 = "2[2[100FR]]"; long Arr1[] = {10000 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findAreas(Arg0)); }
	void test_case_3() { string Arg0 = "47[100FR]"; long Arr1[] = {10000 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findAreas(Arg0)); }
	void test_case_4() { string Arg0 = "1000000[]"; long Arr1[] = { }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findAreas(Arg0)); }
	void test_case_5() { string Arg0 = "4[6FR]FR6FL2FL6FR3FRFR6FL2FL6F"; long Arr1[] = {1, 2, 2, 3, 3, 4, 6, 6, 9 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, findAreas(Arg0)); }
	void test_case_6() { string Arg0 = "4[6FR]FR6FL2FL6FR3FRFR6FL2FL4F"; long Arr1[] = {1, 2, 2, 3, 3, 4, 6, 15 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, findAreas(Arg0)); }
	void test_case_8() { string Arg0 = "3FRFRFLFLFRFR3FRFRFLFLFRF"; long Arr1[] = {7 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(7, Arg1, findAreas(Arg0)); }
	void test_case_7() { string Arg0 = "R19200[FLFFRFRFFL]FLFL39447F"; long Arr1[] = {7 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(7, Arg1, findAreas(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PolylineAreas ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

