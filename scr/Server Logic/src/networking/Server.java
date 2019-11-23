package networking;

import game.MatchHandler;

import java.beans.ExceptionListener;
import java.io.*;
import java.util.*;
import java.net.*;

public class Server {
    static MatchHandler matchHandler = new MatchHandler();

    /**
     *Function that starts the server, only requires a port number
     * @param port to connect to
     */
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
                ClientHandler clientHandler = new ClientHandler(socket, dataInputStream, dataOutputStream, matchHandler);
            }catch(Exception connectionException){
                connectionException.printStackTrace();
            }
        }
    }
}
