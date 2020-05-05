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
    bool checkIfCanBreak(string s1, string s2) {
        sort(ALL(s1));
        sort(ALL(s2));
        int i;
        FOR(i,s1.size()) if(s1[i]<s2[i]) break;
        if(i==s1.size()) return 1;
        FOR(i,s1.size()) if(s2[i]<s1[i]) break;
        if(i==s1.size()) return 1;
        return 0;
        
    }
};

