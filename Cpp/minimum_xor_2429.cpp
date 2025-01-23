class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits1 = cal2Compl(num1);
        int bits2 = cal2Compl(num2);

        if(bits1 == bits2) {
            return num1;
        } else if(bits1 > bits2) {
            return del2Compl(num1, bits1-bits2);
        } else {
            return add2Compl(num1, bits2-bits1);
        }
    }

    int cal2Compl(int n) {
        int res = 0;
        do{
            if(n % 2 != 0) {
                res++;
            }
            n = n / 2;
        } while(n != 0);
        return res;
    }

    int del2Compl(int n, int del) {
        int res = n;
        int tmp = 1;
        do {
            if(n % 2 != 0) {
                res -= tmp;
                del--;
            }
            n = n / 2;
            tmp = tmp * 2;
        } while (del != 0);
        return res;
    }

    int add2Compl(int n, int add) {
        int res = n;
        int tmp = 1;
        do {
            if(n == 0) {
                res += tmp;
                tmp = tmp * 2;
                add--;
                continue;
            }
            if(n % 2 == 0) {
                res += tmp;
                add--;
            }
            n = n / 2;
            tmp = tmp * 2;
        } while(add != 0);
        return res;
    }
};