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
    string digitSum(string s, int k) {
        while(s.size()>k) {
			string t;
			while(s.size()) {
				string r=s.substr(0,min(k,(int)s.size()));
				s=s.substr(min(k,(int)s.size()));
				int a=0;
				FORR(c,r) a+=c-'0';
				t+=to_string(a);
			}
			s=t;
		}
		
		return s;
    }
};
