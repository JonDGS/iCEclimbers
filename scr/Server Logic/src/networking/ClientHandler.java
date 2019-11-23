package networking;

import javax.swing.plaf.synth.SynthEditorPaneUI;
import java.io.*;
import java.net.Socket;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import game.MatchHandler;
import utils.Converter;

/**
 * Handler for clients in the server
 */
public class ClientHandler extends Thread {
    final Socket socket;
    final BufferedReader inputStream;
    final PrintWriter outputStream;
    final MatchHandler matchHandler;

    /**
     * Converts command strings to int to be use in switch statement
     * @param command to convert
     * @return integer of command
     */
    private int commandToEnum(String command){
        if(command.equals("getUpdate")){
            return 0;
        }if(command.equals("updatePlayers")){
            return 1;
        }if(command.equals("gameover")){
            return 2;
        }if(command.equals("CREATE")){
            return 3;
        }
        return -1;
    }

    public ClientHandler(Socket socket, BufferedReader dataInputStream, PrintWriter dataOutputStream, MatchHandler matchHandler) {
        this.start();
        this.socket = socket;
        this.inputStream = dataInputStream;
        this.outputStream = dataOutputStream;
        this.matchHandler = matchHandler;
        System.out.println("Client started");
    }

    @Override
    /**
     * Override of the run method from thread which starts communication with the client
     */
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
                    NetPackage netPackage = new NetPackage();
                    netPackage.jsonToNetpackage(receivedData);
                    String data = netPackage.getData();
                    String id = netPackage.getFrom();
                    Converter converter = Converter.getInstance();
                    NetPackage responsePack = new NetPackage();
                    String dataResponse;
                    responsePack.setFrom("Server");
                    Gson gson = new Gson();
                    int command = commandToEnum(netPackage.getCommand());
                    /*if (receivedData.equals("EXIT")) {
                        this.inputStream.close();
                        this.outputStream.close();
                        this.socket.close();
                        return;
                    }*/
                    switch (command){
                        case 0:
                            dataResponse = converter.convertIntegerArrayToString(matchHandler.searchGameByID(id).getUpdate());
                            responsePack.setData(dataResponse);
                            break;
                        case 1:
                            matchHandler.searchGameByID(id).setUpdate(converter.convertStringToIntegerArray(data));
                            break;
                        case 2:
                            //dataResponse = converter.convertIntegerArrayToString(matchHandler.)
                        case 3:
                            int enemies = gson.fromJson("enemies", int.class);
                            int enemieID[] = gson.fromJson("enemieID", int[].class);
                            String gameID = matchHandler.createGame(enemies, enemieID);
                            responsePack.setData(gameID);
                            break;
                    }
                    String response = responsePack.netpackageToJsonString();
                    System.out.println("Sending " + response + " to " + this.socket);
                    this.outputStream.write(response + "\n");
                    this.outputStream.flush();
                }
            } catch (IOException e) {
                e.printStackTrace();
                break;
            }
        }
    }
}
