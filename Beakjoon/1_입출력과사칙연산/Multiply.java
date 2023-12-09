import java.util.Scanner;

public class Multiply {
    public static void main(String [] artgs) {
        // 몫과 나머지를 이용한 풀이
        int a, b;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();

        System.out.println(a * (b % 10));
        System.out.println(a * (b / 10 % 10));
        System.out.println(a * (b / 100));
        System.out.println(a * b);

        // 문자열을 이용한 풀이
        // int a;
        // String b;
        // Scanner sc = new Scanner(System.in);
        // a = sc.nextInt();
        // b = sc.next();

        // System.out.println(a * (b.charAt(2) - '0'));
        // System.out.println(a * (b.charAt(1) - '0'));
        // System.out.println(a * (b.charAt(0) - '0'));
        // System.out.println(a * Integer.parseInt(b));
    }
}
