class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        else if (x < 0) {
            return false;
        }
        
        int nDigits = 0, xBackup = x;
        while (x > 0) {
            nDigits++;
            x /= 10;
        }
        int *digits = new int[nDigits];
        int *forward = digits, *backward = digits + nDigits - 1;
        while (xBackup > 0) {
            *forward = xBackup % 10;
            xBackup /= 10;
            forward++;
        }

        forward = digits;
        int i;
        for (i = 0; i < nDigits / 2; i++) {
            if (*backward != *forward) {
                return false;
            }
            backward--;
            forward++;
        }

        delete [] digits;
        return true;
    }
};
