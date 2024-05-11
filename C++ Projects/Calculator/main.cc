//Logan Praylow
#include "Calculate.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	//gets arguments and puts them into a string array
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " expression\n";
        return EXIT_FAILURE;
    }
	//Gets user input
    std::string expression = argv[1];

    Calculate calculate;
    try {
	    //prints results
        double result = calculate.calculateExpression(expression);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
	    //prints if there was error
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

