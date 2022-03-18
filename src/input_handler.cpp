#include "input_handler.h"

void InputHandler::handle() {
    int _input;
    do{
        printEditorInstructions();
        std::cin >> _input;
        handleEditorInstructions(_input);
        
    }while(_input != 6);

}

void InputHandler::showInvalidArgument(){
    std::cout << "Invalid instruction. Please try again." << '\n';
};

void InputHandler::printEditorInstructions() {
    std::cout << "Please enter the following instruction number number to start building: " << '\n';
    std::cout << "  1. 'add circle': to add a circle" << '\n';
    std::cout << "  2. 'add rectangle': to add a rectangle" << '\n';
    std::cout << "  3. 'add triangle': to add a triangle" << '\n';
    std::cout << "  4. 'add compound': to add a compound" << '\n';
    std::cout << "  5. 'save': output shape to file" << '\n';
    std::cout << "  6. 'exit': to exit the program" << '\n';
}

void InputHandler::handleEditorInstructions(int instruction) {
    switch(instruction) {
        case 1:
            addCircle();
            break;
        case 2:
            addRectangle();
            break;
        case 3:
            addTriangle();
            break;
        case 4:
            addCompound();
            break;
        case 5:
            save();
            break;
        case 6:
            break;
        default:
            showInvalidArgument();
            break;
    }
}

void InputHandler::save() {
    std::cout << "Please enter the file name to save the shape:" << '\n';
    std::string _fileName="";
    std::cin >> _fileName;
    std::ofstream ofs;

    ofs.open( _fileName + ".txt" );
    
    if (ofs.is_open()) 
        ofs << getOutPutInfo();
    else
        std::cout << "Failed to open file." << '\n' ;
    
    std::cout << "Save complete." << '\n' ;
    ofs.close();
}

void InputHandler::addCircle() {
    std::cout << "Please enter the information of circle:" << '\n';
    std::cout << "Radius of circle: ";

    float _radius = 0;
    std::cin >> _radius;

    try{
        builder -> buildCircle(_radius);
        std::cout << "Circle added." << '\n';
    }catch(...){
        showInvalidArgument();
    }
}

void InputHandler::addRectangle() {
    float _arg[4];
    std::cout << "Please enter the information of rectangle:" << '\n';
    std::cout << "Width of rectangle: ";
    std::cin >> _arg[0];
    std::cout << "Height of rectangle: ";
    std::cin >> _arg[1];

    try{
        builder -> buildRectangle(_arg[0], _arg[1]);
        std::cout << "Rectangle added." << '\n';
    }catch(...){
        showInvalidArgument();
    }
}

void InputHandler::addTriangle() {
    float _arg[4];
    std::cout << "Please enter the information of triangle:" << '\n';
    std::cout << "X1 of triangle: ";
    std::cin >> _arg[0];
    std::cout << "Y1 of triangle: ";
    std::cin >> _arg[1];
    std::cout << "X2 of triangle: ";
    std::cin >> _arg[2];
    std::cout << "Y2 of triangle: ";
    std::cin >> _arg[3];

    try{
        builder -> buildTriangle(_arg[0], _arg[1], _arg[2], _arg[3]);
        std::cout << "Triangle added." << '\n';
    }catch(...){
        showInvalidArgument();
    }
}

void InputHandler::printCompoundInstructions() {
    std::cout << "Please enter the following instruction number to build the compound:" << '\n';
    std::cout << "  1. 'add circle': to add a circle" << '\n';
    std::cout << "  2. 'add rectangle': to add a rectangle" << '\n';
    std::cout << "  3. 'add triangle': to add a triangle" << '\n';
    std::cout << "  4. 'add compound': to add a compound" << '\n';
    std::cout << "  5. 'exit': to exit the program" << '\n';
}

void InputHandler::handleCompoundInstructions(int instruction) {
    switch(instruction) {
        case 1:
            addCircle();
            break;
        case 2:
            addRectangle();
            break;
        case 3:
            addTriangle();
            break;
        case 4:
            addCompound();
            break;
        case 5:
            break;
        default:
            showInvalidArgument();
            break;
    }
}

void InputHandler::addCompound() {
    int _input;
    builder -> buildCompoundBegin();

    do{
        printCompoundInstructions();
        std::cin >> _input;
        handleCompoundInstructions(_input);
    }while(_input != 5);

    builder -> buildCompoundEnd();

    std::cout << "Compound added." << '\n';
}

std::string InputHandler::getOutPutInfo(){
    Shape* _shpae = builder -> getShape();

    ShapeInfoVisitor visitor;
    _shpae->accept(&visitor);

    return visitor.getResult();
}