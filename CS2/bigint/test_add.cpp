// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(123);
      bigint right(456);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 123);
      assert(right  == 456);
      assert(result == 579);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(123);
      bigint right(1111);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 123);
      assert(right  == 1111);
      assert(result == 1234);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(123);
      bigint right(11);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 123);
      assert(right  == 11);
      assert(result == 134);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(999);
      bigint right(99);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 999);
      assert(right  == 99);
      assert(result == 1098);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(78);
      bigint right(222);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 78);
      assert(right  == 222);
      assert(result == 300);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(78);
      bigint right(999);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 78);
      assert(right  == 999);
      assert(result == 1077);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(66);
      bigint right(890);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 66);
      assert(right  == 8903);
      assert(result == 8969);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(97);
      bigint right(40);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 97);
      assert(right  == 40);
      assert(result == 137);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(2);
      bigint right(99999999999999999999);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 2);
      assert(right  == 99999999999999999999);
      assert(result == 100000000000000000001);
    }
    
    std::cout << "Done with testing addition." << std::endl;
}

