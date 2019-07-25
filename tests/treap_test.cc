// Copyright 2019 Yan Song

#include "../src/streamingcc_include/treap.h"
#include <ctime>
#include <cstdlib>
#include <random>
#include <boost/test/unit_test.hpp>

#define BOOST_TEST_MODULE ClassTest
#define BOOST_TEST_DYN_LINK

BOOST_AUTO_TEST_CASE(Treap_test) {
        using streamingcc::Treap;

        int n = 1e6;
        Treap treap;
        // Insert 1e6 elements into treap
        for (int i = 0; i < n; i++) {
            treap.insert(i);
        }

        // Random select 5 elements to check
        // if these elements are in treap
        srand(time(nullptr));
        for (int i = 0; i < 5; i++) {
            int j = std::rand() % n;
            BOOST_CHECK(treap.find(j)->value == j);
            BOOST_CHECK_MESSAGE();
        }
};
