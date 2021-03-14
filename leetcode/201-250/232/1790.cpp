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
    bool areAlmostEqual(string s1, string s2) {
		if(s1==s2) return 1;
		int x,y;
		FOR(y,s1.size()) {
			FOR(x,y) {
				swap(s1[x],s1[y]);
				if(s1==s2) return 1;
				swap(s1[x],s1[y]);
				
			}
		}
		return 0;
		
        
    }
};
