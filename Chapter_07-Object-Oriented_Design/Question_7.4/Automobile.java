public abstract class Automobile {
    private String license;

    public Automobile(String str) {
        this.license = str;
    }

    public String getLicense() {
        return this.license;
    }

    public abstract void horn();
}
