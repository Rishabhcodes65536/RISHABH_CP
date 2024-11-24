import java.util.*;
import java.io.*;

public class Main {
    static int INF = Integer.MAX_VALUE;

    static int countDivisors(int n) {
        int cnt = 0;
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                if (n / i == i)
                    cnt++;
                else
                    cnt += 2;
            }
        }
        return cnt;
    }

    static int digitsSum(int n) {
        int ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }

    static int binpow(int a, int b, int m) {
        int ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans *= a;
                if (ans > m)
                    ans %= m;
            }
            a *= a;
            if (a > m)
                a %= m;
            b >>= 1;
        }
        return ans;
    }

    static int inv_mod(int b, int mod) {
        return binpow(b, mod - 2, mod) % mod;
    }

    static int FLOOR(int a, int b) {
        if (a > 0 || a % b == 0)
            return a / b;
        return (a / b - 1);
    }

    static int CEIL(int a, int b) {
        return (a + b - 1) / b;
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int POW(int a, int b) {
        return b == 0 ? 1 : a * POW(a, b - 1);
    }

    static int mod_exp(int a, int b, int mod) {
        int res = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res % mod;
    }

    static int mod_mul(int a, int b, int m) {
        a = a % m;
        b = b % m;
        return (((a * b) % m) + m) % m;
    }

    static int mod_sub(int a, int b, int m) {
        a = a % m;
        b = b % m;
        return (((a - b) % m) + m) % m;
    }

    static int extended_gcd(int a, int b, int x, int y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return x;
        }
        int gcd = extended_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return gcd;
    }

    static int mod_inv(int a, int b) {
        int r1, r2;
        int gcd = extended_gcd(a, b, r1, r2);
        assert gcd == 1;
        return r1;
    }

    static int mod_div(int a, int b, int m) {
        a = a % m;
        b = b % m;
        return (mod_mul(a, mod_inv(b, m), m) + m) % m;
    }

    static void dosomething() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (!mp.containsKey(a[i])) {
                mp.put(a[i], new ArrayList<>());
            }
            mp.get(a[i]).add(i);
        }
        Set<Integer> st = new HashSet<>();
        for (int i = 0; i < n; i++) {
            st.add(a[i]);
        }
        List<Integer> uniq = new ArrayList<>(st);
        int maxi = INF;
        for (int k = 0; k < uniq.size() - 1; k++) {
            List<Integer> u = mp.get(uniq.get(k));
            List<Integer> v = mp.get(uniq.get(k + 1));
            int i = 0, j = 0;
            while (i < u.size() && j < v.size()) {
                maxi = Math.min(maxi, Math.abs(u.get(i) - v.get(j)));
                if (u.get(i) < v.get(j)) {
                    i++;
                } else if (u.get(i) > v.get(j)) {
                    j++;
                } else {
                    i++;
                    j++;
                }
            }
        }
        System.out.println(maxi);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        // int t = Integer.parseInt(br.readLine().trim());
        int t = 1;
        while (t-- > 0) {
            dosomething();
        }
        out.flush();
    }
}
