public class Car extends Automobile {
    public Car() {
        super("");
    }

    @Override
    public void horn() {
        System.out.println("BEEP!");
    }
}
