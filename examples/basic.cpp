#include "mage/core/engine.hpp"

int main() {
    mage::Engine engine(GetScreenWidth(), GetScreenHeight(), "MAGE Engine Test");
    engine.run();
    return 0;
}