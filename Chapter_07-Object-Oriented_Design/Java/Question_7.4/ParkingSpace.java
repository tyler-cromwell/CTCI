public abstract class ParkingSpace {
    private Automobile occupant;

    public ParkingSpace(Automobile a) {
        this.occupant = a;
    }

    public boolean isAvailable() {
        return this.occupant == null;
    }

    public Automobile getOccupant() {
        return this.occupant;
    }

    public void park(Automobile a) {
        this.occupant = a;
    }

    public Automobile vacate() {
        Automobile a = this.occupant;
        this.occupant = null;
        return a;
    }
}
