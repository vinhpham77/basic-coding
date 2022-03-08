package motor.yamaha;

import motor.Motor;

public class Yamaha {

    public static void main(String[] args) {
        Motor[] motor = new Motor[6];
        motor[0] = new Jupiter();
        motor[1] = new Jupiter();
        motor[2] = new Jupiter();
        motor[3] = new Serius();
        motor[4] = new Serius();
        motor[5] = new Serius();
        
        for (int i = 0; i < motor.length; i++) {
            motor[i].inputInfo();
        }
        for (int i = 0; i < motor.length - 1; i++) {
            for (int j = i + 1; j < motor.length; j++) {
                if (motor[i].getWarranty() > motor[j].getWarranty()) {
                    Motor temp = motor[i];
                    motor[i] = motor[j];
                    motor[j] = temp;
                }    
            }
        }
        for (Motor motor1 : motor) {
            motor1.displayInfo();
        }
        System.out.println("\n");
        for (Motor motorTT : motor) {
            if (motorTT.getName().equals("Serius")) {
                motorTT.displayInfo();
            }
        }
        System.out.println("\n");
        for (Motor motor1 : motor) {
            motor1.displayInfo();
        }
    }
}
