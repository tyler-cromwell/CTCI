/*************************************************
 * Part of solution to question 7.3 - Jukebox
*************************************************/

public class Song {
    private String title;
    private String artist;
    private String album;
    private long length;    // seconds

    public Song(String title, String artist, String album, long length) {
        this.title = title;
        this.artist = artist;
        this.album = album;
        this.length = length;
    }

    @Override
    public String toString() {
        return this.title +" by "+ this.artist;
    }

    public String getTitle() {
        return this.title;
    }

    public String getArtist() {
        return this.artist;
    }

    public String getAlbum() {
        return this.album;
    }

    public long getLength() {
        return this.length;
    }

    public String getTime() {
        return ((long) (this.length / 60)) +":"+ String.format("%02d", this.length % 60);
    }
}
