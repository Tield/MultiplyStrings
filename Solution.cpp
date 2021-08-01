class str {
public:
    
    string s;
    str() {}
    str(string f) {
        s = f;
    }
    str operator + (str const &t) {
        string ts = t.s;
		reverse(ts.begin(), ts.end());
        reverse(s.begin(), s.end());
		str result;
        int carry = 0, i = 0;
		for(i = 0; i < min(s.size(), ts.size()); ++i) {
            int x = (ts[i] - '0') + (s[i] - '0') + carry;
            result.s += (x % 10 + '0'), carry = x / 10;
        }
		while(i < s.size()) {
            int x = (s[i] - '0') + carry;
            result.s += (x % 10 + '0'), carry = x / 10;
            i++;
        }
		while(i < ts.size()) {
            int x = (ts[i] - '0') + carry;
            result.s += (x % 10 + '0'), carry = x / 10;
            i++;
        }
        if(carry) result.s += ('0' + carry);
		reverse(result.s.begin(), result.s.end());
        return result;
    }
    
    str operator * (str const &t) {
        str main_ans;
        string ts = t.s;
		reverse(s.begin(), s.end());
        reverse(ts.begin(), ts.end());
        int cnt = 0;
		for(char c : ts) {
            str ans;
            int carry = 0;
			for(char vbn : s) {
                int x = (vbn  - '0') * (c - '0') + carry;
                ans.s += (char)('0' + x % 10), carry = x / 10;
            }
            if(carry) ans.s += (char)(carry + '0');
            reverse(ans.s.begin(), ans.s.end());
            for(int j = 0; j < cnt; ++j) ans.s += '0';
            main_ans = main_ans + ans;
            cnt++;
        }
        reverse(s.begin(), s.end());
        return main_ans;
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        str obj1, obj2;
        obj1.s = num1, obj2.s = num2;
        str obj3 = (obj1*obj2);
        return obj3.s;
    }	
};
