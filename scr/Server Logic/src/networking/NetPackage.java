package networking;

import com.google.gson.Gson;
import com.google.gson.JsonObject;

/**
 * Class that manages the JSON conversion and interpretation from the sockets
 */
public class NetPackage {
    private String from = "NONE";
    private String command = "NONE";
    private String data = "NONE";
    private String type = "NONE";

    /**
     * Sets the info of the jsonData from the socket
     * @param jsonData to be processed
     */
    public void jsonToNetpackage(String jsonData){
        Gson gson = new Gson();
        JsonObject json = gson.fromJson(jsonData, JsonObject.class);
        this.from = json.get("NetPackage").getAsJsonObject().get("from").getAsString();
        this.command = json.get("NetPackage").getAsJsonObject().get("command").getAsString();
        this.data = json.get("NetPackage").getAsJsonObject().get("data").getAsString();
        this.type = json.get("NetPackage").getAsJsonObject().get("type").getAsString();
    }

    /**
     * Convert the contents of the class back to a JSON string
     * @return JSON string
     */
    public String netpackageToJsonString(){
        Gson gson = new Gson();
        JsonObject attributes = (JsonObject) gson.toJsonTree(this);
        JsonObject root = new JsonObject();
        root.add("NetPackage", attributes);
        return gson.toJson(root);
    }

    public String getFrom() {
        return from;
    }

    public String getCommand() {
        return command;
    }

    public String getData() {
        return data;
    }

    public String getType() {
        return type;
    }

    public void setFrom(String from) {
        this.from = from;
    }

    public void setCommand(String command) {
        this.command = command;
    }

    public void setData(String data) {
        this.data = data;
    }

    public void setType(String type) {
        this.type = type;
    }
}
