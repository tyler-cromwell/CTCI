public class CarSpace extends ParkingSpace {
    public CarSpace() {
        super(null);
    }

    public CarSpace(Car a) {
        super(a);
    }

    @Override
    public Car getOccupant() {
        return (Car) super.getOccupant();
    }

    @Override
    public Car vacate() {
        return (Car) super.vacate();
    }
}
