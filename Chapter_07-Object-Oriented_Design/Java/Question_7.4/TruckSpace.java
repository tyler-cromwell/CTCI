public class TruckSpace extends ParkingSpace {
    public TruckSpace() {
        super(null);
    }

    public TruckSpace(Truck a) {
        super(a);
    }

    @Override
    public Truck getOccupant() {
        return (Truck) super.getOccupant();
    }

    @Override
    public Truck vacate() {
        return (Truck) super.vacate();
    }
}
