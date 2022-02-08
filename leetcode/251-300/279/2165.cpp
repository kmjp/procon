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
    long long smallestNumber(long long num) {
		int m=0;
		if(num==0) return 0;
		if(num<0) {
			m=1;
			num=-num;
		}
		string S=to_string(num);
		sort(ALL(S));
		if(m==0) {
			int i;
			FOR(i,S.size()) if(S[i]!='0') {
				swap(S[0],S[i]);
				break;
			}
			num=atoll(S.c_str());
		}
		else {
			reverse(ALL(S));
			num=-atoll(S.c_str());
		}
        return num;
    }
};
