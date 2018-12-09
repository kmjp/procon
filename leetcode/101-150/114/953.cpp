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

int rev[256];

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int i,j;
        
        FOR(i,26) rev[order[i]]=i;
        
        
        FOR(i,words.size()-1) {
			int x=min(words[i].size(),words[i+1].size());
			if(words[i].substr(0,x)==words[i+1].substr(0,x)) {
				if(words[i].size()>words[i+1].size()) return false;
				continue;
			}
			
			FOR(j,x) {
				if(rev[words[i][j]]<rev[words[i+1][j]]) break;
				if(rev[words[i][j]]>rev[words[i+1][j]]) return false;
			}
			
			
		}
		return true;
        
        
    }
};
