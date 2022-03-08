package DemSNT;

public class DemSNT {

    public static int exec(int n) {
        int[] a = new int[100];
        int dem = 0;
        for (int i = 2; i <= n; i++) {
            float make = (float) Math.sqrt(i);
            if (make < 2) {
                a[dem] = i;
                dem++;
            } else {
                boolean check = true;
                for (int j = 0; j <= dem && a[j] <= make; j++) {
                    if (i % a[j] == 0) {
                        check = false;
                    }
                }
                if (check) {
                    a[dem] = i;
                    dem++;
                }
            }

        }
        return dem;
    }
}
