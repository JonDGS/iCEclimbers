package networking;

import java.beans.ExceptionListener;
import java.io.*;
import java.text.*;
import java.util.*;
import java.net.*;

public class Server {
    public static LinkedList<Socket> clientList = new LinkedList<Socket>();

    public void startServer(int port){
        ServerSocket serverSocket = null;
        try {
            serverSocket = new ServerSocket(port);
        } catch (IOException e) {
            e.printStackTrace();
        }
        //Main loop for accepting client requests
        while(true){
            Socket socket = null;
            try{
                socket = serverSocket.accept();
            }catch(Exception connectionException){
                connectionException.printStackTrace();
            }

        }
    }
}
