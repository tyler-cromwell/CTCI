public class MotorcycleSpace extends ParkingSpace {
    public MotorcycleSpace() {
        super(null);
    }

    public MotorcycleSpace(Motorcycle a) {
        super(a);
    }

    @Override
    public Motorcycle getOccupant() {
        return (Motorcycle) super.getOccupant();
    }

    @Override
    public Motorcycle vacate() {
        return (Motorcycle) super.vacate();
    }
}
