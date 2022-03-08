package PTB2;

public class PTB2 {

    private final int a;
    private final int b;
    private final int c;

    public PTB2(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public char xetDau(int so) {
        if (so >= 0) {
            return '+';
        } else {
            return '-';
        }
    }

    public void hienThi() {
        System.out.println(a + "x^2 " + xetDau(b) + " " + Math.abs(b) + "x " + xetDau(c) + " " + Math.abs(c) + " = 0");
    }

    public void giaiPT() {
        int delta = b * b - 4 * a * c;
        if (delta < 0) {
            System.out.println("Phuong trinh vo nghiem");
        }
        if (delta == 0) {
            double x = -b / (2 * a);
            System.out.println("x1 = x2 = " + x);
        }
        if (delta > 0) {
            double x1 = (-b - Math.sqrt(delta)) / (2 * a);
            double x2 = (-b + Math.sqrt(delta)) / (2 * a);
            System.out.println("x1 = " + x1 + ", x2 = " + x2);
        }
    }
}
