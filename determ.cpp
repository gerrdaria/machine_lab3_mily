#include <iostream>
#include <string>
#include <stdexcept>

class DeterministicAutomat {
private:
    enum State {  B, C, D, E, F, O, S } currentState;
    char x;  
    int y;  

public:
    DeterministicAutomat() : currentState(S), x('a'), y(0) {}

    void process(const std::string& input) {


        for (char ch : input) {
            if (ch != 'a' && ch != 'b') {
                throw std::invalid_argument("input 'a' и 'b'.");
            }

            x = ch; 
            switch (currentState) {
                case S:
                    if (x == 'a') {
                        currentState = C;
                        y = 1;
                    } else if (x== 'b') {
                        currentState = O;
                        y = 0;
                    } 
                    break;

                case B:
                    if (x == 'a') {
                        currentState = F;
                        y = 1;
                    } else if (x == 'b') {
                        currentState = D;
                        y = 1;
                    } 
                    break;

                case C:
                    if (x == 'a') {
                        currentState = E;
                        y = 1;
                    } else if (x== 'b') {
                        currentState = B;
                        y = 0;
                    } 
                    break;

                case D:
                    if (x == 'a') {
                        currentState = F;
                        y = 1;
                    } else if (x == 'b') {
                        currentState = D;
                        y= 1;
                    } 
                    break;

                case E:
                    if (x == 'a') {
                        currentState = O;
                        y = 0;
                    } else if (x == 'b') {
                        currentState = E;
                        y = 1;
                    } 
                    break;


                     case F:

                    if (x == 'a') {
                        currentState = O;
                        y = 0;
                    } else if (x == 'b') {
                        currentState = O;
                        y = 0;
                    }
                    break;


                case O:
                    
                    y = 0;
                    break;


              
            }

            

        
            std::cout << "X: " << x << ", Y: " << y << std::endl;
        }

        
        if (y == 1) {
            std::cout << "The word HAS COME (the final state)" << std::endl;
        } else {
            std::cout <<"The word did NOT fit (not the final state)" << std::endl;
        }
    }
};

int main() {
    DeterministicAutomat automat;
    std::string input;
    std::cout << "input'a' и 'b': ";
    std::cin >> input;

    try {
        automat.process(input);
    } catch (const std::invalid_argument& e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    return 0;
}
