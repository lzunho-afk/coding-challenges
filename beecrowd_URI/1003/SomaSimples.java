import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SomaSimples {
    public static void main(String[] args) throws IOException {
        InputStreamReader ir = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(ir);

        int a, b, soma;
        a = Integer.parseInt(in.readLine());
        b = Integer.parseInt(in.readLine());

        soma = a + b;
        System.out.printf(String.format("SOMA = %d\n", soma));
    }
}
