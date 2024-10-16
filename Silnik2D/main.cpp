#include "Engine.h"

int main() {

    Engine engine(800, 600, "SFML Game", false);


    engine.init();


    engine.run();

    return 0;
}
