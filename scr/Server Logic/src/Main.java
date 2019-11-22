import networking.NetPackage;
import com.google.gson.*;
import networking.Server;

public class Main {
    public static void main(String args[]){
        Server mainServer = new Server();
        mainServer.startServer(50000);
    }
}
