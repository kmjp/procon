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

ll X[101010],Y[101010],Z[101010];
int id[101010];
ll mo=1000000007;
vector<ll> added;
set<int> valid;

struct BinarySumTrie {
	BinarySumTrie *nex[2];
	ll v;int num;
	set<int> S;
	BinarySumTrie() {
		nex[0]=nex[1]=NULL;v=0;num=0;
	}
	void add(int s,int id,int flag,int pos=29) {
		if(flag) num++;
		else num--;
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(!nex[c]) nex[c]=new BinarySumTrie();
			nex[c]->add(s,id,flag,pos-1);
		}
		else {
			v=s;
			if(flag) S.insert(id);
			else S.erase(id);
		}
	}
	pair<int,int> pick(int mask,int pos=29) {
		if(pos<0) {
			return {v,*S.begin()};
		}
		
		if(mask&(1<<pos)) {
			if(nex[0] && nex[0]->num) return nex[0]->pick(mask,pos-1);
			return nex[1]->pick(mask,pos-1);
		}
		else {
			if(nex[1] && nex[1]->num) return nex[1]->pick(mask,pos-1);
			return nex[0]->pick(mask,pos-1);
		}
	}
};

class MojisBag {
	public:
	int maximumXor(int Q, int base, int add, int rate) {
		ZERO(Y);
		ZERO(Z);
		added.clear();
		valid.clear();
		
		
		BinarySumTrie* root=new BinarySumTrie();
		
		
		X[0]=add;
		int i;
		pair<int,int> P={-1,-1};
		FOR(i,Q) {
			if(X[i]%rate) {
				added.push_back(X[i]);
				id[i]=added.size()-1;
				
				if(root->num>0) {
					auto p=root->pick(X[i]);
					if(P.first==-1 || (added[P.first]^added[P.second])<(X[i]^p.first)) {
						P={id[i],p.second};
					}
				}
				valid.insert(id[i]);
				root->add(X[i],id[i],1);
			}
			else if(added.size()) {
				int idx=X[i]%added.size();
				if(valid.count(idx)) {
					valid.erase(idx);
					root->add(added[idx],idx,0);
					if(P.first==idx || P.second==idx) {
						P.first=P.second=-1;
						FORR(v,valid) root->add(added[v],v,0);
						FORR(v,valid) {
							if(root->num>0) {
								auto p=root->pick(added[v]);
								if(P.first==-1 || (added[P.first]^added[P.second])<(added[v]^p.first)) {
									P={v,p.second};
								}
							}
							root->add(added[v],v,1);
						}
					}
				}
			}
			if(P.first!=-1) Y[i]=added[P.first]^added[P.second];
			Z[i+1]=(Z[i]*base+Y[i])%mo;
			X[i+1]=(X[i]*base+add)%mo;
		}
		
		return Z[Q];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 4747; int Arg2 = 7; int Arg3 = 3; int Arg4 = 871911884; verify_case(0, Arg4, maximumXor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 47; int Arg2 = 7; int Arg3 = 3; int Arg4 = 34911440; verify_case(1, Arg4, maximumXor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 429; int Arg2 = 3558; int Arg3 = 2; int Arg4 = 0; verify_case(2, Arg4, maximumXor(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MojisBag ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

