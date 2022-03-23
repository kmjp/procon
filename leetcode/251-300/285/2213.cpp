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

set<pair<int,char>> S;
multiset<int> M;

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        S.clear();
        M.clear();
        int i;
        S.insert({-1,'&'});
        M.insert(1);
        FOR(i,s.size()) {
			if(i==0||s[i]!=s[i-1]) {
				S.insert({i,s[i]});
				M.insert(1);
			}
			else {
				auto it=*S.rbegin();
				int len=i-it.first;
				M.erase(M.find(len));
				M.insert(len+1);
			}
		}
        S.insert({s.size(),'&'});
        M.insert(1);
		
		vector<int> ret;
		FOR(i,queryCharacters.size()) {
			int x=queryIndices[i];
			char c=queryCharacters[i];
			auto it2=S.lower_bound({x+1,'\0'});
			auto it=prev(it2);
			int len=it2->first-it->first;
			M.erase(M.find(len));
			auto p=*it;
			auto p2=*it2;
			S.erase(it);
			if(p.first<x) {
				S.insert(p);
				M.insert(x-p.first);
			}
			if(p2.first>x+1) {
				S.insert({x+1,p.second});
				M.insert(p2.first-(x+1));
			}
			p={x,c};
			S.insert(p);
			M.insert(1);
			
			it=S.lower_bound(p);
			it2=next(it);
			if(it->second==it2->second) {
				auto it3=next(it2);
				M.erase(M.find(it3->first-it2->first));
				M.erase(M.find(it2->first-it->first));
				M.insert(it3->first-it->first);
				S.erase(it2);
			}
			it=S.lower_bound(p);
			it2=next(it);
			auto it3=prev(it);
			if(it->second==it3->second) {
				M.erase(M.find(it2->first-it->first));
				M.erase(M.find(it->first-it3->first));
				M.insert(it2->first-it3->first);
				S.erase(it);
			}
			ret.push_back(*M.rbegin());
		}
		return ret;
    }
};
