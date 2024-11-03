import java.nio.charset.Charset;
import java.util.Random;


public abstract class Automobile {
    private String license;

    public Automobile() {
        byte[] array = new byte[10];
        new Random().nextBytes(array);
        this.license = new String(array, Charset.forName("UTF-8"));
    }

    public String getLicense() {
        return this.license;
    }

    public abstract void horn();
}
