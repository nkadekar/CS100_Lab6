#include "gtest/gtest.h"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/sub.hpp"
#include "../header/add.hpp"
#include "../header/op.hpp"
#include "../header/rand.hpp"
#include "../header/pow.hpp"
#include <string>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
