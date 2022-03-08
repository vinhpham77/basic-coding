package svchonhp;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.JOptionPane;

public class GUI implements ActionListener, MouseListener, WindowListener {

    Font nameFont = new Font("Consolas", Font.PLAIN, 17);
    Font questionFont = new Font("Consolas", Font.PLAIN, 15);

    Frame mainFr = new Frame("Học phần sinh viên");
    Frame subFr1 = new Frame("Chọn học phần");
    Frame subFrYesNo = new Frame("Chọn học phần");
    Frame subFr2 = new Frame("Tra cứu");

    Label lbEmpty = new Label("");
    Label lbName = new Label("Họ tên:");
    Label lbName1 = new Label("Họ tên:");
    Label lbName2 = new Label("Họ tên:");
    Label lbQuestion = new Label("Sinh viên đã từng chọn môn học, quyết định chọn lại?");
    Label lbSubjects1 = new Label("Môn học:");
    Label lbSubjects2 = new Label("Môn học đã chọn:");

    TextField tfName = new TextField();
    TextField tfNameC1 = new TextField();
    TextField tfNameC2 = new TextField();

    TextArea taSubjects = new TextArea();

    List lSubjects = new List(20, true);

    //mainFr
    Button bChoose = new Button("Chọn học phần");
    Button bSearch = new Button("Tra cứu");
    //subFr1
    Button bApply = new Button("Hoàn tất");
    Button bBack1 = new Button("Trở lại");
    //subFrYN
    Button bYes = new Button("Có");
    Button bNo = new Button("Không");
    //subFr2
    Button bBack2 = new Button("Trở lại");

    //mainFr
    Panel p1 = new Panel(new GridLayout(2, 1));
    Panel p2 = new Panel(new GridLayout(2, 1));
    Panel p3 = new Panel(new GridLayout(2, 1));
    //subFr1
    Panel p4 = new Panel(new GridLayout(2, 1));
    Panel p5 = new Panel(new GridLayout(1, 1));
    Panel p6 = new Panel(new GridLayout(2, 1));
    //subFrYN
    Panel pQuestion = new Panel(new GridLayout(1, 1));
    Panel pYesNo = new Panel(new GridLayout(1, 2));
    //subFr2
    Panel p7 = new Panel(new GridLayout(2, 1));
    Panel p8 = new Panel(new GridLayout(1, 1));
    Panel p9 = new Panel(new GridLayout(2, 1));

    public GUI() {
        importSubjectsToList();

        initMainFr();
        initSubFr1();
        initSubFrYesNo();
        initSubFr2();
    }

    public void initMainFr() {
        mainFr.setLayout(new GridLayout(3, 2));

        tfName.setFont(nameFont);

        bChoose.addMouseListener(this);
        bChoose.addActionListener(this);
        bSearch.addMouseListener(this);
        bSearch.addActionListener(this);

        p1.add(lbName);
        p1.add(tfName);
        p3.add(bChoose);
        p3.add(bSearch);

        mainFr.add(p1);
        mainFr.add(p2);
        mainFr.add(p3);

        mainFr.addWindowListener(this);
        mainFr.setSize(350, 200);
        mainFr.setVisible(true);
    }

    public void initSubFr1() {
        subFr1.setLayout(new GridLayout(3, 1));

        tfNameC1.setFont(nameFont);
        tfNameC1.setEditable(false);

        bApply.addMouseListener(this);
        bApply.addActionListener(this);
        bBack1.addMouseListener(this);
        bBack1.addActionListener(this);

        p4.add(lbName1);
        p4.add(tfNameC1);
        p5.add(lbSubjects1);
        p5.add(lSubjects);
        p6.add(bApply);
        p6.add(bBack1);

        subFr1.add(p4);
        subFr1.add(p5);
        subFr1.add(p6);

        subFr1.addWindowListener(this);
        subFr1.setSize(350, 200);
        subFr1.setVisible(false);
    }

    public void initSubFr2() {
        subFr2.setLayout(new GridLayout(3, 1));

        tfNameC2.setFont(nameFont);
        tfNameC2.setEditable(false);

        taSubjects.setEditable(false);

        bBack2.addMouseListener(this);
        bBack2.addActionListener(this);

        p7.add(lbName2);
        p7.add(tfNameC2);
        p8.add(lbSubjects2);
        p8.add(taSubjects);
        p9.add(lbEmpty);
        p9.add(bBack2);

        subFr2.add(p7);
        subFr2.add(p8);
        subFr2.add(p9);

        subFr2.addWindowListener(this);
        subFr2.setSize(350, 200);
        subFr2.setVisible(false);
    }

    public void initSubFrYesNo() {
        subFrYesNo.setLayout(new GridLayout(2, 1));
        lbQuestion.setFont(questionFont);
        lbQuestion.setForeground(Color.RED);

        bYes.addMouseListener(this);
        bYes.addActionListener(this);
        bNo.addMouseListener(this);
        bNo.addActionListener(this);

        pYesNo.add(bYes);
        pYesNo.add(bNo);

        subFrYesNo.add(lbQuestion);
        subFrYesNo.add(pYesNo);

        subFrYesNo.addWindowListener(this);
        subFrYesNo.setSize(378, 130);
        subFrYesNo.setVisible(false);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object buttonClicked = e.getSource();
//        String hoTen = tf1.getText();
//        File file = new File("C:\\SVChonHP\\" + hoTen + ".dat");
//
//        if (!hoTen.equals("")) {
//            if (nut == b1) {
//                tf1C1.setText(hoTen);
//                mainFr.setVisible(false);
//                subFr1.setVisible(true);
//            } else if (nut == b2) {
//                boolean thanhCong = true;
//                tf1C2.setText(hoTen);
//                mainFr.setVisible(false);
//                subFr2.setVisible(true);
//                SinhVienHP sv = null;
//
//                try (FileInputStream fis = new FileInputStream(file);
//                        ObjectInputStream ois = new ObjectInputStream(fis)) {
//
//                    sv = (SinhVienHP) ois.readObject();
//                } catch (IOException | ClassNotFoundException ex) {
//                    thanhCong = false;
//                    JOptionPane.showMessageDialog(null,
//                            "Thất bại!",
//                            "Truy xuất",
//                            JOptionPane.ERROR_MESSAGE);
//                }
//
//                if (thanhCong) {
//                    String[] dsMonHoc = sv.layDsMonHoc();
//                    int n = dsMonHoc.length;
//                    ta.setText("");
//
//                    for (int i = 0; i < n; i++) {
//                        ta.append(dsMonHoc[i] + "\n");
//                    }
//
//                    ta.setCaretPosition(0);
//                }
//            } else if (nut == b3) {
//                String[] dsMonChon = l1.getSelectedItems();
//                int[] MonIndexes = l1.getSelectedIndexes();
//                SinhVienHP sv = new SinhVienHP(hoTen, dsMonChon);
//                int n = MonIndexes.length;
//
//                sv.ghiTep(file);
//
//                for (int i = 0; i < n; i++) {
//                    l1.deselect(i);
//                }
//
//                subFr1.setVisible(false);
//                mainFr.setVisible(true);
//            } else if (nut == b4C) {
//                subFr2.setVisible(false);
//                mainFr.setVisible(true);
//            }
//
//        } else {
//            JOptionPane.showMessageDialog(null,
//                    "Chưa điền họ tên!",
//                    "Dữ liệu",
//                    JOptionPane.WARNING_MESSAGE);
//        }

        if (buttonClicked == bChoose) {
            String name = tfName.getText();
            if (!hasWrongFormat(name)) {
                File file = new File("C:\\SVChonHP\\" + name + ".dat");
                mainFr.setVisible(false);

                if (file.getParentFile().mkdirs() || !file.exists()) {
                    enableToChoose();
                } else {
                    subFrYesNo.setVisible(true);
                }
            }
        } else if (buttonClicked == bSearch) {
            String name = tfName.getText();
            if (!hasWrongFormat(name)) {
                boolean isSuccess = true;
                File file = new File("C:\\SVChonHP\\" + name + ".dat");
                SinhVienHP sv = null;

                try (FileInputStream fis = new FileInputStream(file);
                        ObjectInputStream ois = new ObjectInputStream(fis)) {
            
                    sv = (SinhVienHP) ois.readObject();
                } catch (IOException ex) {
                    isSuccess = false;
                    JOptionPane.showMessageDialog(null,
                            "Sinh viên chưa từng chọn môn học!",
                            "Truy xuất",
                            JOptionPane.ERROR_MESSAGE);
                } catch (ClassNotFoundException ex) {
                    isSuccess = false;
                    JOptionPane.showMessageDialog(null,
                            "Không tìm thấy class",
                            "Truy xuất",
                            JOptionPane.ERROR_MESSAGE);
                }

                if (isSuccess) {
                    tfNameC2.setText(name);
                    String[] subjects = sv.getSubjects();
                    int n = subjects.length;
                    taSubjects.setText("");

                    for (int i = 0; i < n; i++) {
                        taSubjects.append(subjects[i] + "\n");
                    }

                    taSubjects.setCaretPosition(0);

                    mainFr.setVisible(false);
                    subFr2.setVisible(true);
                }
            }
        } else if (buttonClicked == bApply) {
            String name = tfName.getText();
            String[] chosenSubjects = lSubjects.getSelectedItems();
            SinhVienHP sv = new SinhVienHP(name, chosenSubjects);
            File file = new File("C:\\SVChonHP\\" + name + ".dat");

            sv.exports(file);

            subFr1.setVisible(false);
            mainFr.setVisible(true);
        } else if (buttonClicked == bBack1 || buttonClicked == bBack2) {
            if (buttonClicked == bBack1) {
                subFr1.setVisible(false);
            } else {
                subFr2.setVisible(false);
            }

            mainFr.setVisible(true);
        } else if (buttonClicked == bYes || buttonClicked == bNo) {
            subFrYesNo.setVisible(false);

            if (buttonClicked == bYes) {
                enableToChoose();
            } else {
                mainFr.setVisible(true);
            }
        }
    }

    public void importSubjectsToList() {
        try (FileReader fr = new FileReader("DSMonHoc.txt");
                BufferedReader br = new BufferedReader(fr)) {

            while (br.ready()) {
                lSubjects.add(br.readLine());
            }
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null,
                    "Truy xuất không như mong đợi!",
                    "Dữ liệu môn học",
                    JOptionPane.ERROR_MESSAGE);
        }
    }

    public boolean hasWrongFormat(String name) {
        if (name.isBlank()) {
            JOptionPane.showMessageDialog(null,
                    "Họ tên không thể trống!",
                    "Thông tin",
                    JOptionPane.ERROR_MESSAGE);
            return true;
        }

        return false;
    }

    public void deselectSubjects() {
        int[] subjectsIndexes = lSubjects.getSelectedIndexes();
        int n = subjectsIndexes.length;

        for (int i = 0; i < n; i++) {
            lSubjects.deselect(subjectsIndexes[i]);
        }
    }

    public void enableToChoose() {
        tfNameC1.setText(tfName.getText());
        deselectSubjects();
        subFr1.setVisible(true);
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        Component c = e.getComponent();
        c.setBackground(Color.LIGHT_GRAY);
    }

    @Override
    public void mouseExited(MouseEvent e) {
        Component c = e.getComponent();
        c.setBackground(Color.WHITE);
    }

    @Override
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
    }

    @Override
    public void mousePressed(MouseEvent e) {
    }

    @Override
    public void mouseReleased(MouseEvent e) {
    }

    @Override
    public void windowOpened(WindowEvent e) {
    }

    @Override
    public void windowClosed(WindowEvent e) {
    }

    @Override
    public void windowIconified(WindowEvent e) {
    }

    @Override
    public void windowDeiconified(WindowEvent e) {
    }

    @Override
    public void windowActivated(WindowEvent e) {
    }

    @Override
    public void windowDeactivated(WindowEvent e) {
    }

}
