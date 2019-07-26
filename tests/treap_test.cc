// Copyright 2019 Yan Song

#include "../src/streamingcc_include/treap.h"
#include "../src/treap.cc"
#define BOOST_TEST_MODULE ClassTest
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

using streamingcc::Treap;
using streamingcc::util::rand_int;

BOOST_AUTO_TEST_CASE(Treap_Test) {
    int n = 100000;
    Treap<int> treap;
    // Insert 1e6 elements into treap
    for (int i = 0; i < n; i++) {
        treap.insert(i);
    }

    // Random select 5 elements to check
    // if these elements are in treap
    for (int i = 0; i < 5; i++) {
        int j = rand_int(n);
        BOOST_CHECK(treap.contains(j));
    }
    BOOST_CHECK(!treap.contains(n));
}

BOOST_AUTO_TEST_CASE(Treap_Test_Reverse) {
    int n = 1000000;
    Treap<int> treap;
    // Insert 1e6 elements into treap
    for (int i = n-1; i >= 0; i--) {
        treap.insert(i);
    }

    // Random select 5 elements to check
    // if these elements are in treap
    for (int i = 0; i < 5; i++) {
        int j = rand_int(n);
        BOOST_CHECK(treap.contains(j));
    }
    BOOST_CHECK(!treap.contains(n));
}
