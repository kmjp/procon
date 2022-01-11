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
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
		set<string> S;
		FORR(a,startWords) {
			sort(ALL(a));
			S.insert(a);
		}
		int ret=0;
		FORR(a,targetWords) {
			sort(ALL(a));
			int i;
			FOR(i,a.size()) {
				string T=a.substr(0,i)+a.substr(i+1);
				if(S.count(T)) {
					ret++;
					break;
				}
			}
		}
        return ret;
    }
};
