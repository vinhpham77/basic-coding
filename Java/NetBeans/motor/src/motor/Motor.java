package motor;

import java.util.Scanner;

public abstract class Motor implements IMotor {

    private String code;
    private String name;
    private double capacity;
    private int num;
    
    public Motor() {
    }

    public Motor(String code, String name, double capacity, int num) {
        this.code = code;
        this.name = name;
        this.capacity = capacity;
        this.num = num;
    }

    @Override
    public void inputInfo() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Input the motor code: ");
        setCode(sc.nextLine());
        System.out.print("Input its name: ");
        setName(sc.nextLine());
        System.out.print("Input its capacity: ");
        setCapacity(sc.nextDouble());
        System.out.print("Input its num: ");
        setNum(sc.nextInt());
    }

    @Override
    public void displayInfo() {
        System.out.println("Code: " + getCode());
        System.out.println("Name: " + getName());
        System.out.println("Capacity: " + getCapacity());
        System.out.println("Num: " + getNum());
    }

    @Override
    public void changeInfo() {
        inputInfo();
    }

    /**
     * @return the code
     */
    public String getCode() {
        return code;
    }

    /**
     * @param code the code to set
     */
    public void setCode(String code) {
        this.code = code;
    }

    /**
     * @return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return the capacity
     */
    public double getCapacity() {
        return capacity;
    }

    /**
     * @param capacity the capacity to set
     */
    public void setCapacity(double capacity) {
        if (capacity > 0) {
            this.capacity = capacity;
        }
    }

    /**
     * @return the num
     */
    public int getNum() {
        return num;
    }

    /**
     * @param num the num to set
     */
    public void setNum(int num) {
        if (num > 0) {
            this.num = num;
        }
    }

    public abstract int getWarranty();
}
