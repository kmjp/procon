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
    bool canBeValid(string s, string locked) {
		if(s.size()%2) return 0;
		int O=s.size()/2,C=s.size()/2;
		int i;
		FOR(i,s.size()) if(locked[i]=='1') {
			if(s[i]=='(') O--;
			if(s[i]==')') C--;
		}
		if(O<0||C<0) return 0;
		int cur=0;
		FOR(i,s.size()) {
			if(locked[i]=='0') {
				if(O) {
					s[i]='(';
					O--;
				}
				else {
					s[i]=')';
				}
			}
			if(s[i]=='(') {
				cur++;
			}
			else {
				cur--;
			}
			if(cur<0) return 0;
		}
        return cur==0;
    }
};
