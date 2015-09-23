#include "map_vs_unordered_map.h"
#include "Dictionary.h"
#include <string>

NS_BEGIN(elloop);
NS_BEGIN(container);

BEGIN_TEST(Container, MapVsUnorderedMap, @);

clock_t begin(0), end(0);

const int kSearchCount(100);
const int kSearchCount2 = 1e2;

EXPECT_EQ(kSearchCount, kSearchCount2);

auto lan = Dictionary::getInstance();
if (lan) {

    srand(time(0));

    const int numOfKeys = lan->numOfKeys();
    std::string* const * keys = lan->keys();
    int randIndex(0);

    // test init.
    begin = clock();
    lan->init("chinese.lang");
    end = clock();
    double timeConsumed = ((double)end - begin) / CLOCKS_PER_SEC;
    p("map load consumed: ");
    psln(timeConsumed);

    // test find.
    begin  = clock();
    for (int i = 0; i < kSearchCount; ++i) {
        randIndex = rand() % numOfKeys;
        if (!keys[randIndex]) {
            continue;
        }
        lan->getValue(*(keys[randIndex]));
    }
    end = clock();
    timeConsumed = ((double)end - begin) / CLOCKS_PER_SEC;
    p("map find consumed: ");
    psln(timeConsumed);

    lan->clear();

    begin = clock();
    lan->initWithHash("chinese.lang");
    end = clock();
    timeConsumed = ((double)end - begin) / CLOCKS_PER_SEC;
    p("hash load consumed: ");
    psln(timeConsumed);

    // test find.
    begin = clock();
    for (int i = 0; i < kSearchCount; ++i) {
        randIndex = rand() % numOfKeys;
        if (!keys[randIndex]) {
            continue;
        }
        lan->getValueFromHash(*(keys[randIndex]));
        //lan->getValueFromHash("@MPQuantity");
    }
    end = clock();
    timeConsumed = ((double)end - begin) / CLOCKS_PER_SEC;
    p("hash find consumed: ");
    psln(timeConsumed);

    lan->clearKeys();
    lan->purge();
}

END_TEST;

NS_END(container);
NS_END(elloop);