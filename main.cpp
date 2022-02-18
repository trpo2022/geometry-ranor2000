#include <iostream>
#include <string>

// buff size = 1 KiB
#define BUFFER_SIZE 1024
#define OBJ_COUNT 1
#define PI 3.1415

// TODO: add other objects
enum ObjectType { empty = -1, circle = 0 };
const std::string objectName[OBJ_COUNT] = {"circle"};

// { <double>, <double> }
typedef struct {
    double x, y;
} Point2d;

typedef struct {
    Point2d position;
    double radius;
} ObjectCircle;

// unsafe, redisign
bool isDigit(char c) {
    if ((c == '-') || (c == '.') || (c == '0') || (c == '1') || (c == '2')
        || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7')
        || (c == '8') || (c == '9')) {
        return true;
    }
    return false;
}

void printCircleData(ObjectCircle obj) {
    printf("1. circle(%.4lf, %.4lf, %.4lf)\n",
           obj.position.x,
           obj.position.y,
           obj.radius);

    double perimeter = 2 * PI * obj.radius;
    double area = PI * obj.radius * obj.radius;

    printf("\tperimeter = %.4lf\n", perimeter);
    printf("\tarea = %.4lf\n", area);
}

// return true if get error
bool parseInputString(const char* str, ObjectCircle& object) {
    const std::string input = str;

    ObjectType objectType = empty;
    for (int objType = 0; objType < OBJ_COUNT; objType++) {
        if (input.find(objectName[objType]) != std::string::npos) {
            objectType = ObjectType(objType);
            break;
        }
    }

    int countOfBrackets = -1;
    int countOfNumbers = -1;
    double* rawNumber;

    switch (objectType) {
    case empty: {
        printf("ERROR #1: Incorrect object type. expected at column #0: "
               "'circle'\n");
        return true;
    }
    case circle: {
        countOfBrackets = 1;
        countOfNumbers = 2 * 1 + 1;
        rawNumber = new double[countOfNumbers];
        break;
    }
    }

    // iterator for string
    int it = objectName[objectType].length();

    // open brackets
    for (int i = 0; i < countOfBrackets; i++) {
        if (input[it++] != '(') {
            printf("ERROR #2: Not enought open brackets at column #%d: "
                   "expected '('\n",
                   --it);
            return true;
        }
    }

    // numbers
    for (int i = 0; i < countOfNumbers; i++) {
        std::string buff("");
        while (isDigit(input[it])) {
            buff += input[it++];
        }

        rawNumber[i] = std::stod(buff);

        if (input[it] == ',') {
            it++;
            continue;
        }

        if (buff.length() != 0 && input[it] == ')') {
            break;
        }

        printf("ERROR #4: expected <double> at column #%d\n", --it);
        return true;
    }

    switch (objectType) {
    case empty: {
        printf("ERROR #unknown: unknown error");
        break;
    }
    case circle: {
        object.position = {rawNumber[0], rawNumber[1]};
        object.radius = rawNumber[2];
        break;
    }
    default: {
        printf("ERROR #unknown: unknown error");
    }
    }

    // closing brackets
    for (int i = 0; i < countOfBrackets; i++) {
        if (input[it++] != ')') {
            printf("ERROR #3: Not enought closing brackets at column #%d"
                   "expected '('\n",
                   --it);
            return true;
        }
    }

    return false;
}

int main() {
    char buffer[BUFFER_SIZE] = {0};

    printf("Input object data: ");
    scanf("%s", buffer);

    ObjectCircle obj;
    if (!parseInputString(buffer, obj)) {
        printCircleData(obj);
    }

    return 0;
}