package networking;

import com.google.gson.Gson;
import com.google.gson.JsonObject;

public class NetPackage {
    private String from;
    private String command;
    private String data;
    private String type;

    public void jsonToNetpackage(String jsonData){
        Gson gson = new Gson();
        JsonObject json = gson.fromJson(jsonData, JsonObject.class);
        this.from = json.get("NetPackage").getAsJsonObject().get("from").getAsString();
        this.command = json.get("NetPackage").getAsJsonObject().get("command").getAsString();
        this.data = json.get("NetPackage").getAsJsonObject().get("data").getAsString();
        this.type = json.get("NetPackage").getAsJsonObject().get("type").getAsString();
    }

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
