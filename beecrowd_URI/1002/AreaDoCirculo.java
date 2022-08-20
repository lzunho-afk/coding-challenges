import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ExtremamenteBasico {
    public static void main(String[] args) throws IOException {
        InputStreamReader ir = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(ir);

        Double raio, area;
        raio = Double.parseDouble(in.readLine());
        area = 3.14159 * (raio*raio);

        System.out.printf(String.format("A=%.4f\n", area));
    }
}
