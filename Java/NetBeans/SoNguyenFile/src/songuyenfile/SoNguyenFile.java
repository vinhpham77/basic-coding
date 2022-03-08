package songuyenfile;

import java.io.*;
import java.util.Scanner;

public class SoNguyenFile {

    public static void createFile(String filePath) {
        try {
            FileOutputStream fos = new FileOutputStream(filePath);
            try (DataOutputStream dos = new DataOutputStream(fos)) {
                int numsPositiveInterger = (int) (Math.random() * 100 + 1); //random 1 to 100
                for (int i = 1; i <= numsPositiveInterger; i++) {
                    int randomValue = (int) (Math.random() * 1000 + 1); //random 1 to 1000
                    dos.writeBytes(String.valueOf(randomValue));
                    dos.writeBytes(i % 10 == 0 ? "\n" : " ");
                }
            }
        } catch (IOException e) {
            System.out.println("ERROR. Creating " + filePath + "is unexpected");
        }
    }

    public static void mergeFiles(String srcFilePath1,
            String srcFilePath2,
            String desFilePath) {

        try {
            FileInputStream fis1 = new FileInputStream(srcFilePath1);
            FileInputStream fis2 = new FileInputStream(srcFilePath2);
            FileOutputStream fos = new FileOutputStream(desFilePath);

            try (Scanner sc1 = new Scanner(fis1);
                    Scanner sc2 = new Scanner(fis2);
                    DataOutputStream dos = new DataOutputStream(fos)) {

                int count = 0;
                while (sc1.hasNextInt() || sc2.hasNextInt()) {                    
                    int number = 0;
                    int a = 0;
                    int b = 0;
                    
                    if (sc1.hasNextInt()) {
                        a = sc1.nextInt();
                    }
                    if (sc2.hasNextInt()) {
                        b = sc2.nextInt();
                    }
                    
                    number = a + b;
                    count++;
                    dos.writeBytes(String.valueOf(number));
                    dos.writeBytes(count % 10 == 0 ? "\n" : " ");
                }
            }
        } catch (IOException e) {
            System.out.println("Merging " + srcFilePath1 +
                                " and " + srcFilePath2 +
                                " into " + desFilePath);
        }
    }

    public static void output(String srcFilePath, String desFilePath) {
        try {
            FileInputStream fis = new FileInputStream(srcFilePath);
            FileOutputStream fos = new FileOutputStream(desFilePath);

            try (Scanner sc = new Scanner(fis);
                    DataOutputStream dos = new DataOutputStream(fos)) {
                int count = 0;
                while (sc.hasNextInt()) {
                    int number = sc.nextInt();
                    if (number % 2 == 0) {
                        count++;
                        dos.writeBytes(String.valueOf(number));
                        dos.writeBytes(count % 10 == 0 ? "\n" : " ");
                    }
                }
            }
        } catch (IOException e) {
            System.out.println("ERROR. Creating " + desFilePath
                    + " from " + srcFilePath + " is unexpected");
        }
    }

    public static void main(String[] args) {
//        createFile("songuyen1.txt");
//        createFile("songuyen2.txt");
//        mergeFiles("songuyen1.txt", "songuyen2.txt", "songuyen.txt");
//        output("songuyen.txt", "sochan.txt");
        System.out.println("Chỗ, gối");
    }
}
