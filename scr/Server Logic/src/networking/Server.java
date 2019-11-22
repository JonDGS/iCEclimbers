package networking;

import java.beans.ExceptionListener;
import java.io.*;
import java.util.*;
import java.net.*;

public class Server {

    public void startServer(int port){
        System.out.println("Server running at port " + port + "...");
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
                BufferedReader dataInputStream = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter dataOutputStream = new PrintWriter(socket.getOutputStream(), true) ;
            }catch(Exception connectionException){
                connectionException.printStackTrace();
            }
        }
    }
}
