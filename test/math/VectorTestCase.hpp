#ifndef TEST_VECTORTESTCASE_HPP
#define TEST_VECTORTESTCASE_HPP

#include <cppunit/extensions/HelperMacros.h>
#include "math/Vector.hpp"
 
using namespace oopse;


typedef Vector<double, 3> Vec3; 
typedef Vector<double, 4> Vec4;

class VectorTestCase : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE( VectorTestCase );
    CPPUNIT_TEST(testConstructors);
    CPPUNIT_TEST(testArithmetic);
    CPPUNIT_TEST(testAccessEntries);
    CPPUNIT_TEST(testOtherTemplateFunctions);
    CPPUNIT_TEST_SUITE_END();

    public:
        virtual void setUp();
        virtual void tearDown();

        void testConstructors();
        void testArithmetic();
        void testOperators();
        void testAccessEntries();
        void testOtherTemplateFunctions();
        
};

#endif //TEST_VECTORTESTCASE_HPP
