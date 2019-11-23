#include <stdio.h>
#include "Networking/Connector.h"
#include "Networking/NetPackage.h"
#include "utils/Converter.h"

int main() {
    /*char* test = convertToJSON("America", "What", "AK", "Important");
    printf("%s\n", test);
    char* from = getSenderFromJSON(test);
    printf("%s\n", from);
    char* command = getCommandFromJSON(test);
    printf("%s\n", command);
    char* data = getDataFromJSON(test);
    printf("%s\n", data);
    char* type = getTypeFromJSON(test);
    printf("%s\n", type);*/
    char* response = sendRequest("Computer", "Destroy", "Run", "America");
    printf("%s\n", response);
    return 0;
}