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
    int largestInteger(int num) {
		string S=to_string(num);
		int i,x,y;
		FOR(i,S.size()) {
			FOR(x,S.size()) {
				FOR(y,x) {
					if(S[x]%2==S[y]%2&&S[x]>S[y]) swap(S[x],S[y]);
				}
			}
		}
        return atoll(S.c_str());
    }
};

