import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Figurinhas {
    public static void main(String[] args) throws IOException {
        InputStreamReader ir = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(ir);

        int n, f1, f2, count;
        n = Integer.parseInt(in.readLine());

        count = 0;
        while (count < n) {
            f1 = Integer.parseInt(in.readLine());
            f2 = Integer.parseInt(in.readLine());

            while (((f1 < f2) && (f2 % f1 != 0)) || ((f2 < f1) && (f1 % f2 != 0))) {
                if (f1 < f2)
                    f2 -= f1;
                else
                    f1 -= f2;

                if (f1 < f2)
                    System.out.printf(String.format("%d\n", f1));
                else
                    System.out.printf(String.format("%d\n", f2));
            }
        }
    }
}
