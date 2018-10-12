import java.util.Scanner;

public class C3 {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        while (true) {
            int X = scanner.nextInt();
            int Y = scanner.nextInt();

            if (X == -1 && Y == -1)
                break;

            System.out.println(X + Y);
        }
    }

}
