public class ParkingLot {
    private ParkingSpace[][] spaces;
    private int levels;
    private int spacesPerLevel;
    private int truckSpaces;
    private int motorcycleSpaces;
    private int carSpaces;

    public ParkingLot(int l, int spl, int ts, int ms) {
        this.levels = l;
        this.spacesPerLevel = spl;
        this.spaces = new ParkingSpace[l][spl];
        this.truckSpaces = ts;
        this.motorcycleSpaces = ms;
        this.carSpaces = (l * spl) - ts - ms;

        if (ts == 0 && ms == 0) {
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < spl; j++) {
                    this.spaces[i][j] = new CarSpace();
                }
            }
        }
        else if (ts > 0 && ms == 0) {
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < spl; j++) {
                    if (ts > 0) {
                        this.spaces[i][j] = new TruckSpace();
                        ts--;
                    } else {
                        this.spaces[i][j] = new CarSpace();
                    }
                }
            }
        }
        else if (ts == 0 && ms > 0) {
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < spl; j++) {
                    if (ms > 0) {
                        this.spaces[i][j] = new MotorcycleSpace();
                        ms--;
                    } else {
                        this.spaces[i][j] = new CarSpace();
                    }
                }
            }
        }
        else {
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < spl; j++) {
                    if (ts > 0) {
                        this.spaces[i][j] = new TruckSpace();
                        ts--;
                    } else if (ms > 0) {
                        this.spaces[i][j] = new MotorcycleSpace();
                        ms--;
                    } else {
                        this.spaces[i][j] = new CarSpace();
                    }
                }
            }
        }
    }

    public TruckSpace getAvailableTruckSpace() {
        if (this.truckSpaces == 0) {
            return null;
        }

        for (int i = 0; i < this.levels; i++) {
            for (int j = 0; j < this.spacesPerLevel; j++) {
                ParkingSpace ps = this.spaces[i][j];

                if (ps.isAvailable() && ps instanceof TruckSpace) {
                    return (TruckSpace) ps;
                }
            }
        }

        return null;
    }

    public MotorcycleSpace getAvailableMotorcycleSpace() {
        if (this.motorcycleSpaces == 0) {
            return null;
        }

        for (int i = 0; i < this.levels; i++) {
            for (int j = 0; j < this.spacesPerLevel; j++) {
                ParkingSpace ps = this.spaces[i][j];

                if (ps.isAvailable() && ps instanceof MotorcycleSpace) {
                    return (MotorcycleSpace) ps;
                }
            }
        }

        return null;
    }

    public CarSpace getAvailableCarSpace() {
        if (this.carSpaces == 0) {
            return null;
        }

        for (int i = 0; i < this.levels; i++) {
            for (int j = 0; j < this.spacesPerLevel; j++) {
                ParkingSpace ps = this.spaces[i][j];

                if (ps.isAvailable() && ps instanceof CarSpace) {
                    return (CarSpace) ps;
                }
            }
        }

        return null;
    }
}
