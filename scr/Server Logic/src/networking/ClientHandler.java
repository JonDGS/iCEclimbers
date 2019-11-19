package networking;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;

public class ClientHandler extends Thread {
    private Socket socket;
    private DataInputStream inputStream;
    private DataOutputStream outputStream;

    public ClientHandler(Socket socket, DataInputStream dIS, DataOutputStream dOS){
        this.socket = socket;
        this.inputStream = dIS;
        this.outputStream = dOS;
    }
}
