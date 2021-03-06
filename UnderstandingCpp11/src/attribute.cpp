#include "attribute.h"

NS_BEGIN( elloop )
NS_BEGIN( attribute )

#ifdef _MSC_VER
#else
[[noreturn]]void throwAway() {
    throw "away";
}
#endif


void foo() {
    pln( "in foo" );
#ifdef _MSC_VER
    pln( "vc don't work" );
#else
    throwAway();
#endif
    pln( "can't reach here" );
}

BEGIN_TEST( Attribute, NoReturn, @);
    foo();
END_TEST;



NS_END( attribute )
NS_END( elloop )