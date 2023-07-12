import java.util.Scanner;

public class Remain {
    public static void main(String [] args) {
        int a, b, c, l, m, n, o;

        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        l = (a + b) % c;
        m = (a % c + b % c) % c;
        n = a * b % c;
        o = ((a % c) * (b % c)) % c;

        System.out.println(l);
        System.out.println(m);
        System.out.println(n);
        System.out.println(o);
    }
}
