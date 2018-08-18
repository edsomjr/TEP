import java.util.Scanner;

public class C2 {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();

        for (int i = 0; i < T; ++i) {
            int X = scanner.nextInt();
            int Y = scanner.nextInt();

            System.out.println(X + Y);
        }
    }

}
