package utils;

import com.google.gson.Gson;

/**
 * Singleton for converting type from string and back
 */
public class Converter {
    private static Converter ourInstance = new Converter();

    public static Converter getInstance() {
        return ourInstance;
    }

    private Converter() {
    }

    /**
     * Converts the state of the game from matrix to string
     * @param gameState retrieve from game session
     * @return String of the matrix
     */
    public String convertIntegerArrayToString(int[][] gameState){
        String data = new Gson().toJson(gameState);
        return data;
    }

    /**
     * Converts a matrix String back into an array
     * @param data String of the matrix
     * @return int array
     */
    public int[][] convertStringToIntegerArray(String data){
        int[][] newData;
        newData = new Gson().fromJson(data, int[][].class);
        return newData;
    }
}
