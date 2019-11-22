package networking;

import jdk.nashorn.internal.ir.annotations.Ignore;

import javax.swing.plaf.synth.SynthEditorPaneUI;
import java.io.*;
import java.net.Socket;

import game.MatchHandler;

public class ClientHandler extends Thread {
    final Socket socket;
    final BufferedReader inputStream;
    final PrintWriter outputStream;
    final MatchHandler matchHandler;

    public ClientHandler(Socket socket, BufferedReader dataInputStream, PrintWriter dataOutputStream, MatchHandler matchHandler) {
        this.start();
        this.socket = socket;
        this.inputStream = dataInputStream;
        this.outputStream = dataOutputStream;
        this.matchHandler = matchHandler;
        System.out.println("Client started");
    }

    @Override
    public void run(){
        System.out.println("Starting client thread for " + this.socket);
        String receivedData;
        while(true){
            try {
                String entryData;
                while(this.socket.getInputStream().available() > 0) {
                    entryData = this.inputStream.readLine();
                    int numberOfLines = Integer.valueOf(entryData) - 1;
                    receivedData = "";
                    for (int i = 0; i < numberOfLines; i++) {
                        receivedData += this.inputStream.readLine();
                    }
                    System.out.println("Received: " + receivedData);
                    if (receivedData.equals("EXIT")) {
                        this.inputStream.close();
                        this.outputStream.close();
                        this.socket.close();
                        return;
                    }
                    this.outputStream.write(receivedData + "\n");
                    this.outputStream.flush();
                }
            } catch (IOException e) {
                e.printStackTrace();
                break;
            }
        }
    }
}
