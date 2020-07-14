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

	vector<string> split(const string &str, char delim=' '){
		vector<string> res;
		size_t current = 0, found;
		while((found = str.find_first_of(delim, current)) != string::npos){
			res.push_back(string(str, current, found - current));
			current = found + 1;
		}
		res.push_back(string(str, current, str.size() - current));
		return res;
	}

string S[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

class Solution {
public:
    string reformatDate(string date) {
		auto v=split(date);
		int a=0,b=0,c=0;
		FORR(x,v[0]) {
			if(x>='0' && x<='9') {
				a=a*10+x-'0';
			}
		}
		int i;
		FOR(i,12) if(v[1]==S[i]) b=1+i;
		FORR(x,v[2]) {
			if(x>='0' && x<='9') {
				c=c*10+x-'0';
			}
		}
		
		char buf[1010];
		sprintf(buf,"%04d-%02d-%02d",c,b,a);
		return buf;
		
        
    }
};


