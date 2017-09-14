import java.util.ArrayList;

public class Jukebox {
    private ArrayList<Song> songs;

    public Jukebox() {
        this.songs = new ArrayList<Song>();
    }

    public ArrayList<Song> getSongs() {
        return this.songs;
    }

    public Song getSong(int index) {
        return this.songs.get(index);
    }

    public void addSong(Song song) {
        this.songs.add(song);
    }
}
