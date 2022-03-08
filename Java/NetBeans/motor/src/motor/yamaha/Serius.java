package motor.yamaha;

import java.util.Scanner;

public class Serius extends motor.Motor{
    private int warranty;

    public Serius() {
    }

    public Serius(int warranty) {
        this.warranty = warranty;
    }

    public Serius(int warranty, String code, String name, double capacity, int num) {
        super(code, name, capacity, num);
        this.warranty = warranty;
    }

    @Override
    public void inputInfo() {
        Scanner sc = new Scanner(System.in);
        super.inputInfo(); //To change body of generated methods, choose Tools | Templates.
        System.out.print("Input warranty period(months): ");
        setWarranty(sc.nextInt());
    }

    @Override
    public void displayInfo() {
        super.displayInfo(); //To change body of generated methods, choose Tools | Templates.
        System.out.println("Warranty period: " + warranty + " month(s)");
    }

    @Override
    public void changeInfo() {
        inputInfo();
    }

    public void setWarranty(int warranty) {
        if (warranty > 0) {
            this.warranty = warranty;
        }
    }

    public int getWarranty() {
        return warranty;
    }
}