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
        this.from = json.get("from").getAsString();
        this.command = json.get("command").getAsString();
        this.data = json.get("data").getAsString();
        this.type = json.get("type").getAsString();
    }

    public String netpackageToJsonString(){
        return new Gson().toJson(this);
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
}
