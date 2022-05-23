public class Main {
    public static void main(String[] args) {
        String regex = "(\\d{3}\\.){2}\\d{3}-\\d{2}";
        String cpf = "123.456.789-10";

        System.out.println(cpf.matches(regex));     // true

        String text = "12345678910";
        System.out.println(text.matches(regex));     // false

        text = "123-456-789-10";
        System.out.println(text.matches(regex));     // false

        text = "123.456.789-1";
        System.out.println(text.matches(regex));     // false

        text = "23.456.789-10";
        System.out.println(text.matches(regex));     // false
    }
}
