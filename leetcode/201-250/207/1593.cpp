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


class Solution {
public:
	int dfs(string& s ,int cur, vector<string>& V) {
		if(cur==s.size()) return V.size();
		int ma=0;
		for(int nex=cur+1;nex<=s.size();nex++) {
			string t=s.substr(cur,nex-cur);
			int ng=0;
			FORR(v,V) if(v==t) ng=1;
			if(ng==0) {
				V.push_back(t);
				ma=max(ma,dfs(s,nex,V));
				V.pop_back();
			}
		}
		
		return ma;
	}

    int maxUniqueSplit(string s) {
		int ma=0;
		int i;
		int N=s.size();
		int mask;
		vector<string> V;
        return dfs(s,0,V);
    }
};
