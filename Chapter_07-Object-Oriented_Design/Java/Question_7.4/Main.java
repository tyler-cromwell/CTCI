public class Main {
    public static void main(String[] args) {
        ParkingLot lot = new ParkingLot(2, 10, 4, 2);
        TruckSpace ts = lot.getAvailableTruckSpace();
        MotorcycleSpace ms = lot.getAvailableMotorcycleSpace();
        CarSpace cs = lot.getAvailableCarSpace();

        ts.park(new Truck());
        ts.getOccupant().horn();
        System.out.println(ts.getOccupant().getLicense());
        System.out.println(ts.vacate());

        ms.park(new Motorcycle());
        ms.getOccupant().horn();
        System.out.println(ms.getOccupant().getLicense());
        System.out.println(ms.getOccupant());

        cs.park(new Car());
        cs.getOccupant().horn();
        System.out.println(cs.getOccupant().getLicense());
        System.out.println(cs.getOccupant());
    }
}
