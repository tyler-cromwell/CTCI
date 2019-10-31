public class Truck extends Automobile {
    public Truck() {
        super("");
    }

    @Override
    public void horn() {
        System.out.println("HONK!");
    }
}
