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
    string thousandSeparator(int n) {
		string a=to_string(n);
		string b;
		int i;
		reverse(ALL(a));
		FOR(i,a.size()) {
			if(i%3==0&&i) b+='.';
			b+=a[i];
		}
		reverse(ALL(b));
        return b;
    }
};

