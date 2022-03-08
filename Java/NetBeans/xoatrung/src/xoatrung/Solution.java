package xoatrung;

class Solution {

    public static int removeDuplicates(int[] nums) {
        byte[] newMang = new byte[nums.length];
        int soPT = 0;
        if (nums.length > 0) {
            soPT = 1;
            byte soTrc = (byte) nums[0];
            newMang[0] = (byte) nums[0];
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] > soTrc) {
                    newMang[soPT] = (byte) nums[i];
                    System.out.println(nums[i] + " " + newMang[soPT]);
                    soTrc = (byte) nums[i];
                    System.out.println(soTrc);
                    soPT++;
                }
            }
        }
        return soPT;
    }

    public static int divide(int dividend, int divisor) {
        long i = 0;
        long t = 0;
        long a = (long) dividend * -1;
        long b = Math.abs(divisor);

        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            if (dividend == -2147483648 && divisor == -1) {
//                System.out.println("diviend: " + dividend);
//                System.out.println("divisor: " + divisor);
                return 2147483647;
            }
            while (a >= b) {
                a -= b;
                i++;
            }
//            System.out.println("i1: " + i);
            t = i;
            return (int) t;
        } else {

            i = 0;
            System.out.println("a: " + a + " " + "b: " + b);
            while (a >= b) {
                a = a - b;
//                System.out.println("i2: " + i);
                i++;
            }
//            System.out.println("i2: " + i);
            t = -i;
            return (int) t;
        }
    }

}
