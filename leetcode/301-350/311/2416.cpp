typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int NUMC=26;
class Trie {
public:
	vector<vector<int> > V;
	vector<int> val;
	int find(string s) {
		int cur=0;
		FORR(c,s) if((cur=V[cur][c+1])==0) return -1;
		return cur;
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+1));
		val.push_back(0);
		sort(S.begin(),S.end());
		FORR(s,S) {
			int cur=0;
			FORR(c,s) {
				if(V[cur][c+1]==0) V.push_back(vector<int>(NUMC+1)),val.push_back(0),V[cur][c+1]=V.size()-1;
				cur=V[cur][c+1];
				val[cur]++;
			}
		}
	}
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
		Trie t;
		FORR(w,words) FORR(c,w) c-='a';
		t.create(words);
        vector<int> ret;
        FORR(w,words) {
			int cur=0,sc=0;
			FORR(c,w) {
				cur=t.V[cur][c+1];
				sc+=t.val[cur];
			}
			ret.push_back(sc);
		}
		return ret;
    }
};
