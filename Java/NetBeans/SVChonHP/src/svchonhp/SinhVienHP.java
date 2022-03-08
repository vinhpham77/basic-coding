package svchonhp;

import java.io.*;

public class SinhVienHP implements Serializable {

    private String name;
    private String[] subjects;

    public SinhVienHP(String name, String[] subjects) {
        this.name = name;
        this.subjects = subjects;
    }

    public String[] getSubjects() {
        return subjects;
    }

    public boolean exports(File file) {
        boolean isSuccess = true;

        try (FileOutputStream fos = new FileOutputStream(file);
                ObjectOutputStream oos = new ObjectOutputStream(fos)) {

            oos.writeObject(this);
        } catch (IOException ex) {
            isSuccess = false;
        }

        return isSuccess;
    }
}
