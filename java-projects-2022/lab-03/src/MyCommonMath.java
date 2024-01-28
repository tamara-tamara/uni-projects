public class MyCommonMath {
    static int gcd(int a, int b) {
        if (a == 0) return b;
        if (a < 0)
            a = -a;
        if (a < b) {
            int t = a;
            a = b;
            b = t;
        }
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}
