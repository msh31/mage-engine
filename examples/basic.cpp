#include "mage/core/engine.hpp"

int main() {
    mage::Engine engine(800, 600, "MAGE Engine Test");
    engine.run();
    return 0;
}